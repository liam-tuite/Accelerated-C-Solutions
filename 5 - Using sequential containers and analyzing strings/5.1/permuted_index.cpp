#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>
#include "permuted_index.h"
#include "string_splitter.h"

using std::domain_error;	using std::sort;
using std::string;			using std::vector;

bool compare(const string& a, const string& b)
{
	// convert a and b to lower case and compare
	string lowerA, lowerB;
	typedef string::size_type string_size;

	for(string_size i = 0; i < a.size(); ++i)
		lowerA.push_back(tolower(a[i]));

	for(string_size i = 0; i < b.size(); ++i)
		lowerB.push_back(tolower(b[i]));

	return lowerA < lowerB;
}

int get_rotations(const string& sentence, vector<string>& indices,
		vector<string>& phrases)
{
	/*
	 *	Split the sentence into its rotations, add all phrases to phrases and
	 *	all indices to indices
	 *
	 *	To get the rotations, iterate through the sentence, push everything to
	 *	the left of the iterator into indices and everything to the right into
	 *	phrases.
	 */

	if(sentence.size() == 0){
		throw domain_error("Input sentence is blank");
		return 1;
	}

	vector<string> words = split(sentence);
	vector<string>::iterator it;
	typedef vector<string>::size_type vec_size;

	// add the first rotation outside the loop
	indices.push_back("");
	phrases.push_back(sentence);

	// go through each rotation
	for(it = words.begin() + 1; it != words.end(); ++it){

		// get the index of rotation
		vector<string> index(words.begin(), it);

		string left;
		for(vec_size i = 0; i < index.size() - 1; ++i){
			left += index[i] + " ";
		}

		left += index[index.size() - 1];
		indices.push_back(left);

		// get the phrase of rotation
		vector<string> phrase(it, words.end());

		string right;
		for(vec_size i = 0; i < phrase.size() - 1; ++i){
			right += phrase[i] + " ";
		}

		right += phrase[phrase.size() - 1];
		phrases.push_back(right);
	}

	return 0;
}

int sort(vector<string>& indices, vector<string>& phrases)
{
	/*
	 * 	-	declare two new vectors for indices and phrases
	 *	-	sort a copy of phrases into the new phrases vector
	 *	-	iterate through the sorted copy. Get the match in the actual phrases
	 *		and its corresponding entry in indices, add the index to the new
	 *		indices vector
	 *	-	assign the new vectors to overwrite the originals
	 */

	vector<string> newIndices, newPhrases = phrases;
	sort(newPhrases.begin(), newPhrases.end(), compare);

	vector<string>::iterator it;
	typedef vector<string>::size_type vec_size;
	for(it = newPhrases.begin(); it != newPhrases.end(); ++it){

		for(vec_size i = 0; i < phrases.size(); ++i){
			if(phrases[i] == *it)
				newIndices.push_back(indices[i]);
		}
	}

	indices = newIndices;
	phrases = newPhrases;

	return 0;
}
