#include "XLib.h"
#include <iostream>

int main()
{
	std::string tmp_str = "123";
	std::string tmp_strFlag = "1234";

	bool tmp_b = XLib::endWith(tmp_str, tmp_strFlag);

	std::cout << tmp_b << std::endl;

	return 0;
}