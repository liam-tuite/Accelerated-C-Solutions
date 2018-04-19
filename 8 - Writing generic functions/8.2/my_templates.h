#pragma once

/*	Creates a local variable and initializes it to a copy of t, adds each element in the range [b, e) to the variable, and returns a copy of the
	variable as its result.
*/
template <class In, class T>
T accumulate(In b, In e, T t)
{
	while (b != e)
		t += *b++;
	return t;
}

//	Copies the sequence from [b, e) to the destination denoted by d.
template <class In, class Out>
void copy(In b, In e, Out d)
{
	while (b != e)
		*d++ = *b++;
}

/*	Compares two sequences to determine whether they contain equal values. The first two iterators specify the first sequence. The third argument
	is the starting point for the second sequence. It is assumed that the second sequence is the same size as the first, so there is no need for a
	second ending iterator.
*/
template <class In>
bool equal(In b, In e, In b2)
{
	while (b != e)
		if (*b++ != *b2++)
			return false;
	return true;
}

//	Looks for the value t in the sequence [b, e) and returns an iterator pointing to it, or e if not found.
template <class In, class T>
In find(In b, In e, const T& t)
{
	while (b != e && *b != t)
		++b;
	return b;
}

//	Looks for an element in the sequence [b, e) for which the predicate p is true. Returns an iterator pointing to this element, or e if not found
template <class In, class T>
In find_if(In b, In e, bool p(const T&))
{
	while (b != e && !p(*b))
		++b;
	return b;
}

/*	Partitions the elements in the range [b, e), based on the predicate p, so that elements for which the predicate is true are at the front of
	the container. Returns an iterator to the first element for which the predicate is false, or e if the predicate is true for all elements.
*/
template <class For, class T>
For partition(For b, For e, bool p(const T& t))
{
	// i will hold the location of a found value for which p is false
	For i = b;
	// b increments through the sequence
	while (b != e) {
		// only update i if p is true for the next element
		if (p(*b)) {
			// give the element at i the value of the element at b, increment i
			*i++ = *b;
		}
		// always increment b
		++b;
	}
	return i;
}

/*	Rearranges so that the elements in the range [b, e) that aren't equal to t are at the front of the range. Returns an iterator denoting one
	past the range of these "unremoved" elements.
*/
template <class For, class T>
For remove(For b, For e, const T& t)
{
	// i will hold the location of a found t-value
	For i = b;
	// b increments through the sequence
	while (b != e) {
		// only update i if no t-value was found
		if (*b != t) {
			// give the element at i the value of the element at b, increment i
			*i++ = *b;
		}
		// always increment b
		++b;
	}
	return i;
}

//	Copies all elements in the range [b, e) not equal to t to the destination denoted by d.
template <class In, class Out, class T>
void remove_copy(In b, In e, Out d, T t)
{
	do
		if (*b != t)
			*d++ = *b;
	while (++b != e);
}

//	Copies all elements in the range [b, e) for which the predicate p fails to the destination denoted by d
template <class In, class Out, class T>
void remove_copy_if(In b, In e, Out d, bool p(const T&))
{
	do
		if (!p(*b))
			*d++ = *b;
	while (++b != e);
}

/*	Searches the sequence denoted by [b, e) for the sequence denoted by [b2, e2) and returns an iterator denoting the start of this sequence, or
	e if the search failed.
*/
template <class In>
In search(In b, In e, In b2, In e2)
{
	// iterate through [b, e)
	while (b != e) {
		if (*b == *b2) {
			// if we found a match, search all following corresponding elements until they either do not match or e2 has been reached
			In i = b + 1;
			In j = b2;
			while (++j != e2) {
				if (*i++ != *j) {
					++b;
					break;
				}
			}
			// if we have made it to this point without breaking, b points to the start of the sequence we are searching within [b, e)
			if(j == e2)
				return b;
		}
		else
			++b;
	}
	// if this code has been reached, return b (which is now the end of the first sequence) to indicate failure
	return b;
}

//	Runs the function f on the elements in the range [b, e), storing the result of f in d.
template <class In, class Out, class T>
void transform(In b, In e, Out d, T f(const T&))
{
	while (b != e)
		*d++ = f(*b++);
}