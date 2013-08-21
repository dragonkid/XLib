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
	tmp_vec.push_back(";;");
	tmp_vec.push_back(";;;");
	std::string tmp_strA = ";";
	std::string tmp_strB = ";";
	
	// test start
	DString out_str = "";
	DBool tmp_bResult;
	for (std::vector<DString>::size_type i = 0; i < tmp_vec.size(); ++i)
	{
		tmp_bResult = XLib::XString::subStrWide(tmp_vec[i], tmp_strA, tmp_strB, out_str);
		std::cout << tmp_bResult << "\t" << out_str << std::endl;
	}
	// test end

	return 0;
}