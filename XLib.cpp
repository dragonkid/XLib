#include "XLib.h"

//using namespace XLib;

bool XLib::startWith(const std::string in_str, const std::string in_strFlag)
{
	if ( in_str.length() < in_strFlag.length() )
	{
		return false;
	}

	return (0 == in_str.find(in_strFlag))? true: false;
}

bool XLib::endWith(const std::string in_str, const std::string in_strFlag)
{
	if ( in_str.length() < in_strFlag.length() )
	{
		return false;
	}

	size_t tmp_uiPos = in_str.length() - in_strFlag.length();

	return (tmp_uiPos == in_str.find(in_strFlag, tmp_uiPos));
}

void XLib::spliteStr2Vec(
	const std::string in_str, 
	const std::string in_strFlag, 
	std::vector<std::string>& out_vec
	)
{

}