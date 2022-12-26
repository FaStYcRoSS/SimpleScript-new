#include <Windows.h>
#include <fstream>
#include "checkers.h"
#include "lexer.h"
#include "parser.h"
using namespace std;


template<class T>
wostream& operator<<(wostream& os, const vector<T>& vec)
{
	os << "{";
	if (vec.size() == 1)
	{
		os << *(vec.begin());
	}
	else if (vec.size() == 2)
	{
		os << *(vec.begin()) << ", " << *(vec.begin() + 1);
	}
	else if (vec.size() > 2)
	{
		for (auto iter = vec.begin(); iter != vec.end() - 1; iter++)
		{
			os << *iter << ", ";
		}
		os << *(vec.end() - 1);
	}
	os << "}";
	return os;
}

wostream& operator<<(wostream& os, const Token& token)
{
	os << token.type << " : " << token.value << endl;
	return os;
}

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		wcout << L"Welcome to SimpleScript!\nLet's write this code!\n";
		while (true)
		{
			wcout << ">>> ";
			wchar_t in[256];
			wcin.getline(in, 256);
			vector<Token> tokens = tokenize(in + wstring(L" \n"));
			wcout << tokens << endl;
			wcout << endl;
		}
	}
	else
	{
		SetConsoleCP(CP_UTF8);
		SetConsoleOutputCP(CP_UTF8);
		wifstream out(argv[1]);
		vector<wstring> temp_vec;
		wstring temp;
		wstring str = L"";
		while (getline(out, temp, L'\n'))
		{
			temp_vec.push_back(temp);
		}
		for (wstring temp : temp_vec)
		{
			str += temp + L"\n";
		}
		vector<Token> tokens = tokenize(str);
		wcout << tokens << endl;
		wcout << L"END OF TOKENS" << endl << endl;
		system("pause");
	}
}