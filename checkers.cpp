#include "checkers.h"

bool isnumber(const wstring& str)
{
	int counter_spec = 0;
	bool boolean = false;
	char str_0;
	try {
		str_0 = str.at(0);
	}
	catch (exception ex)
	{
		return false;
	}
	switch (str.at(0))
	{
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '.':
		boolean = true;
		break;
	default:
		return false;
		break;
	}
	for (wchar_t i : str)
	{
		switch (i)
		{
		case L'0':
		case L'1':
		case L'2':
		case L'3':
		case L'4':
		case L'5':
		case L'6':
		case L'7':
		case L'8':
		case L'9':
			boolean = true;
			break;
		case L'.':
		case L'e':
			++counter_spec;
			boolean = true;
			break;
		default:
			return false;
			break;
		}
	}
	return boolean && (counter_spec == 1 || counter_spec == 0);
}

bool iscomment(const wstring& str)
{
	return str == L"//" || str == L"/*" || str == L"*/";
}

bool isspecsymbol(const wstring& str)
{
	bool boolean = false;
	for (wchar_t i : str)
	{
		switch (i)
		{
		case L'@':
		case L'#':
		case L'^':
		case L'&':
		case L'(':
		case L')':
		case L'[':
		case L']':
		case L'{':
		case L'}':
		case L',':
		case L'.':
		case L'$':
			boolean = true;
			break;
		default:
			return false;
			break;
		}
	}
	return boolean;
}

bool iskeyword(const wstring& str)
{
	return str == L"function" || 
			str == L"while" ||
			str == L"for" ||
			str == L"if" ||
			str == L"else" ||
			str == L"and" ||
			str == L"or" ||
			str == L"class" ||
			str == L"break" ||
			str == L"contionue" ||
			str == L"operator" ||
			str == L"true" ||
			str == L"false" ||
			str == L"return";
}

bool isoperator(const wstring& str)
{
	try {
		if (str.size() > 2) return false;
		else if (
			str == L"+" || str == L"-" || str == L"*" || str == L"/" || str == L"%" ||
			str == L"=" || str == L"<" || str == L">"
			)
			return true;
		else if (str.at(0) == L'+' && str.size() == 2)
		{
			if (str.at(1) == L'+' || str.at(1) == L'=') return true;
			else return false;
		}
		else if (str.at(0) == L'*' && str.size() == 2)
		{
			if (str.at(1) == L'*' || str.at(1) == L'=') return true;
			else return false;
		}
		else if (str.at(0) == L'-' && str.size() == 2)
		{
			if (str.at(1) == L'-' || str.at(1) == L'=') return true;
			else return false;
		}
		else if (str.at(0) == L'/' && str.size() == 2)
		{
			if (str.at(1) == L'=') return true;
			else return false;
		}
		else if (str.at(0) == L'%' && str.size() == 2)
		{
			if (str.at(1) == L'=') return true;
			else return false;
		}
		else if (str.at(0) == L'=' && str.size() == 2)
		{
			if (str.at(1) == L'=') return true;
			else return false;
		}
		else if (str.at(0) == L'<' && str.size() == 2)
		{
			if (str.at(1) == L'=') return true;
			else return false;
		}
		else if (str.at(0) == L'>' && str.size() == 2)
		{
			if (str.at(1) == L'=') return true;
			else return false;
		}
		else return false;
	}
	catch (exception ex)
	{
		return false;
	}
}

bool isnumber_without_dot(const wstring& str)
{
	bool boolean = false;
	for (wchar_t i : str)
	{
		switch (i)
		{
		case '0':
		case '1':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			boolean = true;
			break;
		default:
			return false;
			break;
		}
	}
	return boolean;
}

bool isFORMATstring(const wstring& str)
{
	char str_0;
	char str_1;
	try {
		str_0 = str.at(0);
		str_1 = str.at(str.size() - 1);
	}
	catch (exception ex)
	{
		return false;
	}
	if ((str.at(0) == L'f' && str.at(1) == L'\'' && str.at(str.size() - 1) == L'\'' && str.size() > 2) ||
		(str.at(0) == L'f' && str.at(1) == L'\"' && str.at(str.size() - 1) == L'\"' && str.size() > 2)) return true;
	else return false;
}

bool isnew_line(const wstring& str)
{
	bool boolean = false;
	for (wchar_t i : str)
	{
		switch (i)
		{
		case L'\n':
		case L'\r':
			boolean = true;
			break;
		default:
			return false;
			break;
		}
	}
	return boolean;
}

bool isspace(const wstring& str)
{
	bool boolean = false;
	for (wchar_t i : str)
	{
		switch (i)
		{
		case L' ':
		case L'\t':
			return true;
		default:
			return false;
			break;
		}
	}
}

bool isRAWstring(const wstring& str)
{
	char str_0;
	char str_1;
	try {
		str_0 = str.at(0);
		str_1 = str.at(str.size() - 1);
	}
	catch (exception ex)
	{
		return false;
	}
	if ((str.at(0) == L'r' && str.at(1) == L'\'' && str.at(str.size() - 1) == L'\'' && str.size() > 2) ||
		(str.at(0) == 'r' && str.at(1) == L'\"' && str.at(str.size() - 1) == L'\"' && str.size() > 2)) return true;
	else return false;

}

bool isstring(const wstring& str)
{
	char str_0;
	char str_1;
	try {
		str_0 = str.at(0);
		str_1 = str.at(str.size() - 1);
	}
	catch (exception ex)
	{
		return false;
	}
	if ((str.at(0) == L'\'' && str.at(str.size() - 1) == L'\'' && str.size() > 1) ||
		(str.at(0) == L'\"' && str.at(str.size() - 1) == L'\"' && str.size() > 1)) return true;
	else return false;
}

bool isbeginofstring(const wstring& str)
{
	char str_1;
	char str_0;
	try {
		str_0 = str.at(0);
		str_1 = str.at(1);
	}
	catch (exception ex)
	{
		return false;
	}
	if ((str.at(0) == L'\'' || str.at(0) == L'\"') ||
		(str.at(0) == L'r' && (str.at(1) == L'\'' || str.at(1) == L'\"')) ||
		(str.at(0) == L'f' && (str.at(1) == L'\'' || str.at(1) == L'\"'))) return true;
	else return false;
}