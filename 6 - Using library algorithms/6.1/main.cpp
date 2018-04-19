#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;		using std::max;
using std::cout;	using std::string;
using std::endl;	using std::vector;

string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for (vector<string>::size_type i = 0; i != v.size(); ++i)
		maxlen = max(maxlen, v[i].size());

	return maxlen;
}

vector<string> frame(const vector<string>& v)
{
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen + 4, '*');

	// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for (vector<string>::const_iterator i = v.begin(); i != v.end(); ++i) {
		string s1 = "* " + *i;
		string s2 = string(maxlen - i->size(), ' ') + " *";
		ret.push_back(s1 + s2);
	}

	// write the bottom border
	ret.push_back(border);
	return ret;
}

vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	// add 1 to leave a space between pictures
	string::size_type width1 = width(left) + 1;

	// indicesto look at elements from left and right respectively
	vector<string>::const_iterator i = left.begin(), j = right.begin();

	// continue until we've seen all rows from both pictures
	while (i != left.end() || j != right.end()) {
		// construct new string to hold characters from both pictures
		string s;

		// copy a row from the left-hand side, if there is one
		if (i != left.end())
			s = *i++;

		// pad to full width
		s += string(width1 - s.size(), ' ');

		// copy a row from the right-hand side, if there is one
		if (j != right.end())
			s += *j++;

		// add s to the picture we're creating
		ret.push_back(s);
	}

	return ret;
}

int main(){

	// read both messages
	string left1 = "This";
	string left2 = "is";
	string left3 = "a";
	string left4 = "sample";
	string left5 = "message";

	string right1 = "This is";
	string right2 = "another";
	string right3 = "message";

	vector<string> left, right;

	left.push_back(left1);		left.push_back(left2);		left.push_back(left3);
	left.push_back(left4);		left.push_back(left5);

	right.push_back(right1);	right.push_back(right2);	right.push_back(right3);

	cout << endl;

	vector<string> lframe = frame(left), rframe = frame(right);
	typedef vector<string>::const_iterator iter;
	for(iter i = lframe.begin(); i != lframe.end(); ++i)
		cout << *i << endl;

	cout << endl;

	for(iter i = rframe.begin(); i != rframe.end(); ++i)
		cout << *i << endl;

	cout << endl;

	vector<string> cat = hcat(lframe, rframe);
	for(iter i = cat.begin(); i != cat.end(); ++i)
		cout << *i << endl;

	return 0;
}
