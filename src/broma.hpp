#pragma once

#include "err.hpp"
#include "ast.hpp"
#include "lex.hpp"
#include "parse.hpp"
#include <fstream>

Root parseFile(char const* fname) {
	ifstream in(fname);
	string contents;
	while (in)
		in >> contents;

	stringstream stream;
	stream << contents;

	vector<Token> t = lexStream(stream);
	return parseTokens(t);
}