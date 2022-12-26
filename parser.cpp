#include "parser.h"
#include <unordered_map>
wstring escape_char(const wchar_t& esc)
{
	switch (esc)
	{
	case L'n':
		return L"\n";
	case L't':
		return L"\t";
	case L'r':
		return L"\r";
	case L'a':
		return L"\a";
	case L'v':
		return L"\v";
	case L'\\':
		return L"\\";
	case L'\'':
		return L"'";
	case L'"':
		return L"\"";
	default:
		return wstring(1, esc);
		break;
	}
}

wstring escape_str(wstring str)
{
	wstring new_str = L"";
	for (wstring::iterator iter = str.begin(); iter != str.end(); ++iter)
	{
		if (*iter == L'\\')
		{
			new_str.append(escape_char(*(iter + 1)));
			*(iter + 1) = NULL;
		}
		else
		{
			new_str.push_back(*iter);
		}
	}
	return new_str;
}

unordered_map<string, unordered_map<string, string>> variables;

class ExprNode
{
public:
	virtual ~ExprNode() {}
};

class NumberNode : ExprNode
{
public:
	long double number;
	NumberNode(const long double& num) : number(num) {}
};

class VarNode : ExprNode
{
public:
	string name;
	VarNode(const string& name) : name(name) {}
};

class InitNode : ExprNode
{
public:
	string name;
	string type;
	InitNode(const string& name, const string& type): name(name), type(type) {}
};