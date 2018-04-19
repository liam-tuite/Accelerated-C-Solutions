#pragma once

#include <cstdlib>
#include <istream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "split.h"

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);
bool bracketed(const std::string&);
void gen_aux(const Grammar&, std::vector<std::string>&, std::vector<std::string>&);
int nrand(int n);