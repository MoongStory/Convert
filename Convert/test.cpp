#include "Convert.h"

int main()
{
	MOONG::CONVERT::Convert convert;

	std::string temp000("temp000");
	convert.STRING_TO_WCHAR(temp000);

	std::string temp001("temp001");
	convert.STRING_TO_WCHAR(temp001);

	return EXIT_SUCCESS;
}