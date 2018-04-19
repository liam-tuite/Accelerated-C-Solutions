#include "test.h"

using std::back_inserter;	using std::string;
using std::endl;			using std::vector;
using std::ostream;

bool isnegative(const int& i)
{
	return i < 0;
}

int square(const int& i)
{
	return i * i;
}

void setup_accumulate_vecs(vector<int>& v1, vector<double>& v2)
{
	v1.clear();
	v2.clear();

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.3);
	v2.push_back(4);
}

void setup_copy_vecs(vector<int>& v1, vector<int>& v2)
{
	v1.clear();
	v2.clear();

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
}

void setup_equal_vecs(vector<int>& v1, vector<int>& v2)
{
	v1.clear();
	v2.clear();

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
}

void setup_find_vec(vector<int>& v)
{
	v.clear();

	v.push_back(0);
	v.push_back(0);
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);
}

void setup_find_if_vec(vector<int>& v)
{
	v.clear();

	v.push_back(0);
	v.push_back(4);
	v.push_back(-1);
	v.push_back(7);
}

void setup_partition_vec(vector<int>& v)
{
	v.clear();

	v.push_back(-1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(-1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
}

void setup_remove_vec(vector<int>& v)
{
	v.clear();

	v.push_back(2);
	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
}

void setup_remove_copy_vecs(vector<int>& v1, vector<int>& v2)
{
	v1.clear();
	v2.clear();

	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(3);
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(1);
}

void setup_remove_copy_if_vecs(vector<int>& v1, vector<int>& v2)
{
	v1.clear();
	v2.clear();

	v1.push_back(1);
	v1.push_back(-1);
	v1.push_back(2);
	v1.push_back(-2);
	v1.push_back(3);
	v1.push_back(-3);
}

void setup_search_vecs(vector<int>& v1, vector<int>& v2)
{
	v1.clear();
	v2.clear();

	v1.push_back(0);
	v1.push_back(2);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
}

void setup_transform_vecs(vector<int>& v1, vector<int>& v2)
{
	v1.clear();
	v2.clear();

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
}

bool test_accumulate()
{
	vector<int> v1;
	vector<double> v2;
	setup_accumulate_vecs(v1, v2);

	int sum1 = accumulate(v1.begin(), v1.end(), 0);
	double sum2 = accumulate(v2.begin(), v2.end(), 0.0);

	return sum1 == 10 && sum2 == 10.6;
}

bool test_copy()
{
	vector<int> v1, v2;
	setup_copy_vecs(v1, v2);

	::copy(v1.begin(), v1.end(), back_inserter(v2));
	return equal(v1.begin(), v1.end(), v2.begin());
}

bool test_equal()
{
	vector<int> v1, v2;
	setup_equal_vecs(v1, v2);

	return equal(v1.begin(), v1.end(), v2.begin());
}

bool test_find()
{
	vector<int> v;
	setup_find_vec(v);

	const int i = 1;
	return ::find(v.begin(), v.end(), i) == v.begin() + 3;
}

bool test_find_if()
{
	vector<int> v;
	setup_find_if_vec(v);

	return find_if(v.begin(), v.end(), isnegative) == v.begin() + 2;
}

bool test_partition()
{
	vector<int> v;
	setup_partition_vec(v);

	return partition(v.begin(), v.end(), isnegative) == v.begin() + 2;
}

bool test_remove()
{
	vector<int> v;
	setup_remove_vec(v);

	const int i = 2;
	return remove(v.begin(), v.end(), i) == v.begin() + 5;
}

bool test_remove_copy()
{
	vector<int> v1, v2;
	setup_remove_copy_vecs(v1, v2);

	const int i = 0;
	remove_copy(v1.begin(), v1.end(), back_inserter(v2), i);

	return v2.size() == 2;
}

bool test_remove_copy_if()
{
	vector<int> v1, v2;
	setup_remove_copy_if_vecs(v1, v2);

	remove_copy_if(v1.begin(), v1.end(), back_inserter(v2), isnegative);

	return v2[0] == 1 && v2[1] == 2 && v2[2] == 3;
}

bool test_search()
{
	vector<int> v1, v2;
	setup_search_vecs(v1, v2);

	return search(v1.begin(), v1.end(), v2.begin(), v2.end()) == v1.begin() + 2;
}

bool test_transform()
{
	vector<int> v1, v2;
	setup_transform_vecs(v1, v2);

	transform(v1.begin(), v1.end(), back_inserter(v2), square);
	return v2[0] == 1 && v2[1] == 4 && v2[2] == 9;
}

void test(ostream& out, const string& name, bool test_func())
{
	out << "Testing " << name << " function: ";
	if (test_func())
		out << "passed" << endl;
	else
		out << "FAILED" << endl;
}

void test_all(ostream& out)
{
	// test equal
	test(out, "equal", test_equal);

	// test search
	test(out, "search", test_search);

	// test find
	test(out, "find", test_find);

	// test find_if
	test(out, "find_if", test_find_if);

	// test copy
	test(out, "copy", test_copy);

	// test remove_copy
	test(out, "remove_copy", test_remove_copy);

	// test remove_copy_if
	test(out, "remove_copy_if", test_remove_copy_if);

	// test remove
	test(out, "remove", test_remove);

	// test transform
	test(out, "transform", test_transform);

	// test partition
	test(out, "partition", test_partition);

	// test accumulate
	test(out, "accumulate", test_accumulate);
}