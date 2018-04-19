#pragma once

#include <cstdlib>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "split.h"

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
bool bracketed(const std::string&);
int nrand(int n);
template <class Out> Out gen_sentence(Out, const Grammar&);
template <class Out> Out gen_aux(Out, const Grammar&, const std::string&);

template <class Out>
Out gen_sentence(Out out, const Grammar& g)
{
	return gen_aux(out, g, "<sentence>");
}

template <class Out>
Out gen_aux(Out out, const Grammar& g, const std::string& word)
{
	if (!bracketed(word))
		return *out = word;
	else {
		// locate the rule that corresponds to word
		Grammar::const_iterator it = g.find(word);
		if (it == g.end())
			throw std::logic_error("empty rule");

		// fetch the set of possible rules
		const Rule_collection& c = it->second;

		// from which we select one at random
		const Rule& r = c[nrand(c.size())];

		// recursively expand the selected rule
		for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
			gen_aux(out, g, *i);
	}
	return out;
}