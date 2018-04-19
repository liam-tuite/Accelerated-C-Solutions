#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include "Grammar.h"

using std::back_inserter;	using std::list;
using std::cin;				using std::ostream_iterator;
using std::cout;			using std::string;
using std::endl;

int main()
{
	cout << "Enter the rules of the grammar:" << endl;
	Grammar g = read_grammar(cin);

	// generate and output sentence straight to standard output
	cout << "Output to the standard output:" << endl;
	gen_sentence(ostream_iterator<string>(cout, " "), g);

	cout << endl << endl;

	// generate and output sentence to a list<string>
	list<string> l;
	gen_sentence(back_inserter(l), g);

	// output the list
	cout << "Output to a list:" << endl;
	for (list<string>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";

	return 0;
}