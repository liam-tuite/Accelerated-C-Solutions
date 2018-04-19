#pragma once

#include <cstdlib>
#include <istream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "split.h"

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
std::list<std::string> gen_sentence(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, const std::string&, std::list<std::string>&);
int nrand(int n);