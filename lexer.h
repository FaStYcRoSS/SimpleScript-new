#pragma once
#include "checkers.h"

#include <iostream>
#include <vector>

typedef struct Token {
	wstring type;
	wstring value;
} Token;

wstring token_type(const wstring& str);

vector<Token> tokenize(const wstring& str);