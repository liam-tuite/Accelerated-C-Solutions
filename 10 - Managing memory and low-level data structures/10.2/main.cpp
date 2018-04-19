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
	for (size_t i = 0; i < sizeof(d) / sizeof(*d); ++i)
		v.push_back(d[i]);

	cout << "Median of an array: " << median<double>(d, d + 5) << endl;
	cout << "Median of a vector: " << median<double>(v.begin(), v.end()) << endl;

	return 0;
}