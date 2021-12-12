#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _CONVERT_H_
#define _CONVERT_H_

#include <iostream>
#include <atlbase.h>

namespace MOONG
{
	namespace CONVERT
	{
		class Convert
		{
		public:
			Convert();
			~Convert();

			LPCTSTR STRING_TO_LPCTSTR(std::string source);
			LPCWCHAR STRING_TO_WCHAR(std::string source);
			PCHAR STRING_TO_CHAR(std::string source);
		private:
			wchar_t* string_wchar;
			char* string_char;
		};
	}
}

#endif _CONVERT_H_