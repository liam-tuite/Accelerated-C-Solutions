#include "Grammar.h"

using std::domain_error;	using std::string;
using std::logic_error;		using std::vector;
using std::istream;

// read a grammar from a given input stream
Grammar read_grammar(istream& in) {

	Grammar ret;
	string line;

	// read the input
	while (getline(in, line)) {

		// split the input into words
		vector<string> entry = split(line);

		if (!entry.empty()) {
			// use the category to store the associated rule
			ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
		}
	}
	return ret;
}

vector<string> gen_sentence(const Grammar& g) {

	vector<string> ret, stack;
	stack.push_back("<sentence>");

	while (!stack.empty()) {
		gen_aux(g, stack, ret);
	}
	return ret;
}

bool bracketed(const string& s) {
	return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_aux(const Grammar& g, vector<string>& stack, vector<string>& ret) {

	string word = stack.back();
	stack.pop_back();

	if (!bracketed(word)) {
		ret.push_back(word);
	}
	else {
		// locate the rule that corresponds to word
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw logic_error("empty rule");

		// fetch the set of possible rules
		const Rule_collection& c = it->second;

		// from which we select one at random
		const Rule& r = c[nrand(c.size())];

		// expand the selected rule by pushing each word to the stack (in reverse)
		for (Rule::const_reverse_iterator it = r.rbegin(); it != r.rend(); ++it)
			stack.push_back(*it);
	}
}

// return a random integer in the range [0, n)
int nrand(int n) {

	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand() / bucket_size;
	while (r >= n);

	return r;
}