/*
 * Permuted index
 * --------------
 *
 * Algorithm:
 * 	-	get input sentences
 * 	-	get rotations for all sentences
 * 	-	sort all rotations
 * 	-	format & output indices (left side) and phrases (right side)
 */
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>
#include "permuted_index.h"

using std::cin;				using std::cout;
using std::domain_error;	using std::endl;
using std::list;			using std::string;
using std::vector;

inline string::size_type maxlen(vector<string> vec)
{
	string::size_type max = 0;

	for(string::size_type i = 0; i < vec.size(); ++i)
		if(vec[i].size() > max)
			max = vec[i].size();

	return max;
}

int main()
{
	// get input sentences
	vector<string> inputs;
	cout << "Enter some sentences, followed by end-of-file:" << endl;
	string sentence;
	while(getline(cin, sentence))
		inputs.push_back(sentence);

	// get rotations
	vector<string> indices, phrases;
	typedef vector<string>::size_type vec_size;
	for(vec_size i = 0; i < inputs.size(); ++i){
		try{
			get_rotations(inputs[i], indices, phrases);
		}catch(domain_error e){
			e.what();
			return 1;
		}
	}

	// sort the rotations
	sort(indices, phrases);

	// format and output
	// leave 3 spaces between each index and phrase
	string::size_type width = maxlen(indices) + 3;

	for(vec_size i = 0; i < indices.size(); ++i){

		string index = indices[i];
		cout << index << string(width - index.size(), ' ')
			 << phrases[i] << endl;
	}

	return 0;
}
