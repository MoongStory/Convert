#include "Convert.h"

MOONG::CONVERT::Convert::Convert() :
	string_wchar(nullptr),
	string_char(nullptr)
{

}

MOONG::CONVERT::Convert::~Convert()
{
	if (string_wchar != nullptr)
	{
		delete[] string_wchar;
	}

	if (string_char != nullptr)
	{
		delete[] string_char;
	}
}

LPCTSTR MOONG::CONVERT::Convert::STRING_TO_LPCTSTR(std::string source)
{
#ifdef _UNICODE
	return this->STRING_TO_WCHAR(source);
#elif _MBCS
	return this->STRING_TO_CHAR(source);
#endif
}

LPCWCHAR MOONG::CONVERT::Convert::STRING_TO_WCHAR(std::string source)
{
	if (this->string_wchar != nullptr)
	{
		ZeroMemory(this->string_wchar, _msize(this->string_wchar));

		delete[] this->string_wchar;
	}

	const size_t new_size = strlen(source.c_str()) + 1;
	size_t converted_chars = 0;
	this->string_wchar = new wchar_t[new_size];
	mbstowcs_s(&converted_chars, this->string_wchar, new_size, source.c_str(), _TRUNCATE);

	return this->string_wchar;
}

PCHAR MOONG::CONVERT::Convert::STRING_TO_CHAR(std::string source)
{
	if (this->string_char != nullptr)
	{
		ZeroMemory(this->string_char, _msize(this->string_char));

		delete[] this->string_char;
	}

	const size_t new_size = (strlen(source.c_str()) + 1) * 2;
	this->string_char = new char[new_size];
	strcpy_s(this->string_char, new_size, source.c_str());

	return this->string_char;
}