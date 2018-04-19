#include <cstdlib>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::domain_error;

// use INT_MAX instead of RAND_MAX
int nrand(int n)
{
	if (n <= 0 || n > INT_MAX)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = INT_MAX / n;
	int r;

	do r = rand() / bucket_size;
	while (r >= n);

	return r;
}

int main()
{
	cout << nrand << endl;

	return 0;
}