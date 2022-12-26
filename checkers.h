#pragma once
#include <string>

using namespace std;

bool isnumber_without_dot(const wstring& str);

bool isnumber(const wstring& str);

bool isspecsymbol(const wstring& str);

bool isoperator(const wstring& str);

bool isFORMATstring(const wstring& str);

bool isnew_line(const wstring& str);

bool isspace(const wstring& str);

bool isRAWstring(const wstring& str);

bool isstring(const wstring& str);

bool isbeginofstring(const wstring& str);

bool iskeyword(const wstring& str);

bool iscomment(const wstring& str);