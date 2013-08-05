#include "XLib.h"
#include <iostream>

int main()
{
	std::string tmp_str = "123";
	std::string tmp_strFlag = "1234";
	XLib::XString::endWith(tmp_str, tmp_strFlag);
	//bool tmp_b = XLib::XString::endWith(tmp_str, tmp_strFlag);

	//std::cout << tmp_b << std::endl;

	return 0;
}