#include <iostream>
#include "Vec.h"

using std::cout;	 using std::endl;

// output the elements of a Vec on a line, separated by commas
template <class T>
void output_vec(const Vec<T>& v)
{
	typename Vec<T>::const_iterator it = v.begin();
	if (it == v.end()) {
		cout << "Vec is empty." << endl;
		return;
	}

	cout << *it;
	while (++it != v.end())
		cout << ", " << *it;
	cout << endl;
}

int main()
{
	// test no-args constructor
	cout << "Vec<int> v1: ";
	Vec<int> v1;
	output_vec(v1);
	
	// test explicit constructor
	cout << "Vec<int> v2(10, 100): ";
	Vec<int> v2(10, 100);
	output_vec(v2);

	// test copy constructor
	cout << "Vec<int> v3 = v2: ";
	Vec<int> v3 = v2;
	output_vec(v3);

	// test assignment operator overload
	cout << "v1 = v2: ";
	v1 = v2;
	output_vec(v1);

	// test dynamic allocation
	cout << "Vec<int> *v4 = new Vec<int>(v1): ";
	Vec<int> *v4 = new Vec<int>(v1);
	output_vec(*v4);

	// test destructor
	cout << "delete v4: ";
	delete v4;
	output_vec(*v4);

	return 0;
}