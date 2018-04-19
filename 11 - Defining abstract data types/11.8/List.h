#pragma once

#include <algorithm>
#include <memory>

// Simplified, naive version of std::list. This does not use nodes, but sorts the container each time an element is added.
template <class T> class List {
public:
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;

	List() { create(); }
	explicit List(size_type n, const T& t = T()) { create(n, t); }
	List(const List& v) { create(v.begin(), v.end()); }
	List& operator=(const List&);
	~List() { uncreate(); }

	void push_back(const T& t) {
		if (avail == limit)
			grow();
		unchecked_append(t);
	}

	void clear() { uncreate(); }
	T* erase(T*);

	size_type size() const { return avail - data; }

	iterator begin() { return data; }
	const_iterator begin() const { return data; }

	iterator end() { return avail; }
	const_iterator end() const { return avail; }

private:
	iterator data;	// first element in the List
	iterator avail;	// (one past) the last element in the List
	iterator limit;	// (one past) the allocated memory

	// facilities for memory allocation
	std::allocator<T> alloc;	// object to handle memory allocation

	// allocate and initialize the underlying array
	void create();
	void create(size_type, const T&);
	void create(const_iterator, const_iterator);

	// destroy the elements in the array and free the memory
	void uncreate();

	// support functions for push_back
	void grow();
	void unchecked_append(const T& t);
};

template <class T>
List<T>& List<T>::operator=(const List& rhs)
{
	// check for self-assignment
	if (&rhs != this) {
		// free the array in the left-hand side
		uncreate();

		// copy the elements from the right-hand side to the left-hand side
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template <class T> void List<T>::create()
{
	data = avail = limit = 0;
}

template <class T> void List<T>::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T>
void List<T>::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> void List<T>::uncreate()
{
	if (data) {
		// destroy (in reverse order) the elements that were constructed
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);

		// return all the space that was allocated
		alloc.deallocate(data, limit - data);
	}
	// reset pointers to indicate that the List is empty again
	data = limit = avail = 0;
}

template <class T> T* List<T>::erase(T* i)
{
	iterator ret = i;

	iterator j = i + 1;
	while (j != avail) {
		*i++ = *j++;
	}

	alloc.destroy(i);
	avail--;
	limit--;

	return ret;
}

template <class T> void List<T>::grow()
{
	// when growing, allocate twice as much space as currently in use
	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

	// allocate new space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	// return the old space
	uncreate();

	// reset pointers to point to the newly allocated space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// assumes avail points at allocated, but uninitialized space
template <class T> void List<T>::unchecked_append(const T& val)
{
	alloc.construct(avail++, val);
	std::sort(data, avail);
}