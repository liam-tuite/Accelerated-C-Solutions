#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using std::cin;				using std::endl;
using std::cout;			using std::sort;
using std::domain_error;	using std::vector;

template <class For>
double median(For b, For e)
{
	typedef typename For::difference_type diff;

	diff size = e - b;

	if (size == 0)
		throw domain_error("median of an empty container");

	sort(b, e);

	diff mid = size / 2;

	return size % 2 == 0 ? (*(b + mid) + *(b + mid - 1)) / 2 : *(b + mid);
}

int main()
{
	cout << "Enter some ints, "
		 << "followed by end-of-file: " << endl;

	vector<int> v;
	int i;
	while (cin >> i)
		v.push_back(i);

	try {
		cout << "Median of ints : " << median(v.begin(), v.end()) << endl;
	}
	catch (domain_error e) {
		cout << "Error: " << e.what() << endl;
	}

	return 0;
}