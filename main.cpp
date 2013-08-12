#include "XLib.h"
#include <iostream>

int main()
{
	std::string tmp_str = ";aaa;;;;";
	std::string tmp_strFlag = ";";
	
	std::vector<std::string> tmp_vec;
	
	// test start
	if ( false == XLib::XString::splitStr2Vec(tmp_str, tmp_strFlag, tmp_vec) )
	{
		std::cout << "split failed." << std::endl;
	}
	for (std::vector<std::string>::size_type i = 0; i < tmp_vec.size(); ++i)
	{
		std::cout << "#" << i + 1 << "\t" << tmp_vec.at(i) << std::endl;	
	}
	tmp_strFlag = ";:";
	XLib::XString::mergeVec2Str(tmp_vec, tmp_strFlag, tmp_str);
	std::cout << tmp_str << std::endl;
	// test end

	return 0;
}