#include <algorithm>
#include <iostream>
#include <vector>

using std::back_inserter;	using std::endl;
using std::copy;			using std::vector;
using std::cout;

/*	we have fixed the problem by using std::back_inserter(v) as the destination of the copy. another solution is to set the size of v when
	constructing it:

	vector<int> v(10);

	With this approach we can use v.begin() as the destination and it will work. However, the back_inserter approach is more flexible, as to
	change the size of v with the second approach would require updating the code in 2 places, as opposed to simply changing the vector u.
*/

int main()
{
	vector<int> u(10, 100);
	vector<int> v;
	copy(u.begin(), u.end(), back_inserter(v));

	// output the vector's contents to verify that it works
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
		cout << *it << endl;
	}

	return 0;
}