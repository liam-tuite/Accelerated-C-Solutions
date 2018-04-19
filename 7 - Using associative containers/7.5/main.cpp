#include <iostream>
#include <list>
#include <string>
#include "Grammar.h"

using std::cin;			using std::list;
using std::cout;		using std::string;
using std::endl;

int main()
{
	// generate the sentence
	list<string> sentence = gen_sentence(read_grammar(cin));

	// write the first word, if any
	list<string>::const_iterator it = sentence.begin();
	if(!sentence.empty()){
		cout << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while(it != sentence.end()){
		cout << " " << *it;
		++it;
	}

	cout << endl;
	return 0;
}