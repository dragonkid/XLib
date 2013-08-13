#include "XLib.h"
#include <iostream>

int main()
{
	std::string tmp_str = "a;;;b;;;;c;";
	std::string tmp_strA = ";;;";
	std::string tmp_strB = ";;";
	
	std::vector<std::string> tmp_vec;
	
	// test start
	XLib::XString::replaceAWithB(tmp_str, tmp_strA, tmp_strB);
	std::cout << tmp_str << std::endl;
	// test end

	return 0;
}