#include "lexer.h"

wstring token_type(const wstring& str)
{
	if (isspecsymbol(str)) return L"spec symbol";
	else if (isnumber(str)) return L"number";
	else if (isstring(str)) return L"string literal";
	else if (isRAWstring(str)) return L"raw string literal";
	else if (isFORMATstring(str)) return L"format string literal";
	else if (isoperator(str)) return L"operator";
	else if (isspace(str)) return L"space";
	else if (isnew_line(str)) return L"new line";
	else if (iscomment(str)) return L"comment";
	else if (iskeyword(str)) return L"keyword";
	else return L"id";
}

/*
	Псевдокод для токенов
	создаём переменну, в которой будет временно хранится символы.
	проходимся по всей строке и смотрим символы.
	если встречается пробел, то
		если до этого была строка, то
			мы её символ суём в строку
		обрабатываем строку на типы
		очищаем переменную
	если встречается разделитель (скобки, запятые), то
		если до этого была строка, то
			мы её символ суём в строку
		то обрабатываем строку, очищаем переменную и затем сам разделитель обрабатываем
		идём дальше
	если встречает знак оператор, то
		если до этого была строка, то
			мы её символ суём в строку

		проверяем какая это строка, 
			если это не оператор, то
				обрабатываем строку и смотрим, какой следующий символ.
					Если это оператор, то суём два эти символа и обрабатываем их. итератор увеличиваем на два

*/

vector<Token> tokenize(const wstring& str)
{
	vector<Token> tokens;
	wstring temp = L"";
	Token temp_token;
	for (wstring::const_iterator i = str.begin(); i != str.end(); ++i)
	{
		switch (*i)
		{
		case L' ':
		case L'\t':
			if (isbeginofstring(temp) && (!isstring(temp) && !isRAWstring(temp) && !isFORMATstring(temp)))
			{
				temp += *i;
				break;
			}

			if (token_type(temp) != L"space")
			{
				temp_token.type = token_type(temp);
				temp_token.value = temp;
				tokens.push_back(temp_token);
				temp = L"";
			}
			break;
		case L'(':
		case L')':
		case L'[':
		case L']':
		case L'{':
		case L'}':
		case L',':
		case L'\n':
			if (isbeginofstring(temp) && (!isstring(temp) && !isRAWstring(temp) && !isFORMATstring(temp)))
			{
				temp += *i;
				break;
			}
			if (token_type(temp) != L"space")
			{
				temp_token.type = token_type(temp);
				temp_token.value = temp;
				tokens.push_back(temp_token);
			}
			temp = wstring(1, *i);
			temp_token.type = token_type(temp);
			temp_token.value = temp;
			tokens.push_back(temp_token);
			temp = L"";
			break;
		case L'.':
			if ((isbeginofstring(temp) && 
				!isstring(temp) && 
				!isRAWstring(temp) && 
				!isFORMATstring(temp)) || isnumber_without_dot(temp) ||
				temp.empty())
			{
				temp += *i;
				break;
			}
			if (token_type(temp) != L"space")
			{
				temp_token.type = token_type(temp);
				temp_token.value = temp;
				tokens.push_back(temp_token);
			}
			temp = wstring(1, *i);
			temp_token.type = token_type(temp);
			temp_token.value = temp;
			tokens.push_back(temp_token);
			temp = L"";
			break;
		case L'+':
		case L'-':
		case L'*':
		case L'/':
		case L'%':
		case L'=':
		case L'<':
		case L'>':
			if (isbeginofstring(temp) && (!isstring(temp) && !isRAWstring(temp) && !isFORMATstring(temp)))
			{
				temp += *i;
				break;
			}
			if (token_type(temp) != L"space")
			{
				temp_token.type = token_type(temp);
				temp_token.value = temp;
				tokens.push_back(temp_token);
			}
			temp = wstring(1, *i);
			switch (*(i + 1))
			{
			case L'+':
			case L'-':
			case L'*':
			case L'/':
			case L'%':
			case L'=':
			case L'<':
			case L'>':
				temp += *(i + 1);
				++i;
			default:
				temp_token.type = token_type(temp);
				temp_token.value = temp;
				tokens.push_back(temp_token);
				temp = L"";
				break;
			}
			break;
		default:
			temp += *i;
			break;
		}
	}
	if (!(temp.empty()))
	{
		temp_token.type = token_type(temp);
		temp_token.value = temp;
		tokens.push_back(temp_token);
		temp = L"";
	}
	temp_token.type = L"EOT";
	temp_token.value = L"EOT";
	tokens.push_back(temp_token);
	return tokens;
}