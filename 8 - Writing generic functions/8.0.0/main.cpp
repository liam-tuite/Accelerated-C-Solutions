#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;			using std::sort;
using std::domain_error;	using std::vector;
using std::endl;

template <class T>
T median(vector<T> v)
{
	typedef typename vector<T>::size_type vec_sz;

	vec_sz size = v.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(v.begin(), v.end());

	vec_sz mid = size / 2;
	return size % 2 == 0 ? (v[mid] + v[mid - 1]) / 2 : v[mid];
}

int main()
{
	vector<int> ints;
	for (int i = 0; i < 10; ++i)
		ints.push_back(i);

	vector<double> doubles;
	for (double i = 0.1; i < 10.1; ++i)
		doubles.push_back(i);

	cout << "median of ints: " << median<int>(ints) << endl;
	cout << "median of doubles: " << median<double>(doubles) << endl;

	return 0;
}