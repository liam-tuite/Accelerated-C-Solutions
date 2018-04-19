#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

/*	This function is necessary to be able to call reverse without either specifying a type parameter T, or an object parameter of type T, or
	returning a value of type T. In any of these cases, T will be defined when the function is called. But if we want reverse to be void and/or
	to only take two iterators as parameters, delegating the swap function (which can return a type T) is necessary to create a temporary value
	of type T.
*/
template <class T>
void swap(T& t1, T& t2)
{
	T tmp = t1;
	t1 = t2;
	t2 = tmp;
}

template <class Bi>
void reverse(Bi begin, Bi end)
{
	while (begin != end) {
		--end;
		if (begin != end)
			swap(*begin++, *end);
	}
}

int main()
{
	cout << "Enter some ints, "
		 << "followed by end-of-file: " << endl;
	vector<int> v;
	int i;
	while (cin >> i)
		v.push_back(i);

	::reverse(v.begin(), v.end());

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << endl;
	
	return 0;
}