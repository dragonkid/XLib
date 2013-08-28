#include "XLib.h"
#include <iostream>

int main()
{
	std::vector<DString> tmp_vec;
	//tmp_vec.push_back("<a>as</a><a>asdfasdf</a>");
	//tmp_vec.push_back("</a>adf<a>asdfas<a>fa");
	//tmp_vec.push_back("adf<a>asdfas</a>fa");
	//tmp_vec.push_back("adf;asdf");
	//tmp_vec.push_back("<a>asdf</a>wqe</a>");
	//tmp_vec.push_back("<a><a>wqe</a>");
	//tmp_vec.push_back(";");
//	tmp_vec.push_back(";;");
//	tmp_vec.push_back(";;;");
//	std::string tmp_strA = ";";
//	std::string tmp_strB = ";";

	// test start
    std::string tmp_str = "255.1.1a.1";
    std::cout << XLib::StringTools::isValidIPAddress(tmp_str) << std::endl;

	// test end

	return 0;
}
