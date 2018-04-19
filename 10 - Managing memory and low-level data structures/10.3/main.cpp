#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;			using std::sort;
using std::domain_error;	using std::vector;
using std::endl;

template <class T, class Ran>
T median(Ran b, Ran e)
{
	if (b == e)
		throw domain_error("median of an empty vector");

	// add elements to temporary vector, so we can sort this vector without affecting the order of the original container
	vector<T> v;
	while (b != e)
		v.push_back(*b++);
	sort(v.begin(), v.end());

	typedef typename vector<T>::size_type vec_sz;
	vec_sz size = v.size();
	vec_sz mid = size / 2;

	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

int main()
{
	double d[] = {4, 1, 2, 5, 3};
	vector<double> v;
	const size_t d_size = sizeof(d) / sizeof(*d);
	for (size_t i = 0; i < d_size; ++i)
		v.push_back(d[i]);

	// Output array before calling median
	cout << "Original array: " << endl;
	for (size_t i = 0; i < d_size; ++i)
		cout << d[i] << " ";
	// Output median of array
	cout << endl << "Median of array: " << median<double>(d, d + 5) << endl;
	// Output array after calling median
	cout << "Array post-median call: " << endl;
	for (size_t i = 0; i < d_size; ++i)
		cout << d[i] << " ";

	// Output vector before calling median
	cout << endl << endl << "Original vector:" << endl;
	typedef vector<double>::const_iterator iter;
	for (iter it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";
	// Output median of vector
	cout << endl << "Median of vector: " << median<double>(v.begin(), v.end()) << endl;
	// Output vector after calling median
	cout << "Vector post-median call: " << endl;
	for (iter it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";

	return 0;
}