#include "xString.h"

XSPACE_BEGIN

bool XString::startWith(const std::string in_str, const std::string in_strFlag)
{
	if ( in_strFlag.empty() || (in_str.length() < in_strFlag.length()) )
	{
		return false;
	}

	return (0 == in_str.find(in_strFlag))? true: false;
}

bool XString::endWith(const std::string in_str, const std::string in_strFlag)
{
	if ( in_strFlag.empty() || (in_str.length() < in_strFlag.length()) )
	{
		return false;
	}

	size_t tmp_uiPos = in_str.length() - in_strFlag.length();

	return (tmp_uiPos == in_str.find(in_strFlag, tmp_uiPos));
}

bool XString::splitStr2Vec(
	const std::string in_str, 
	const std::string in_strFlag, 
	std::vector<std::string>& out_vec
	)
{
	out_vec.clear();

	if ( in_str.empty() || ("" == in_str) || (in_strFlag.length() != 1) )
	{
		return false;
	}

	std::string tmp_strTmp = in_str;
	// did not find in_strFlag at the end of in_str
	if ( in_str.find_last_of(in_strFlag) != (in_str.length() - in_strFlag.length()) )
	{
		tmp_strTmp.append(in_strFlag);
	}

	// start to divide
	std::string::size_type tmp_uiPosStart = 0;
	std::string::size_type tmp_uiPosEnd = 0;
	while ( std::string::npos != (tmp_uiPosEnd = tmp_strTmp.find(in_strFlag, tmp_uiPosStart)) )
	{
		out_vec.push_back(tmp_strTmp.substr(tmp_uiPosStart, tmp_uiPosEnd - tmp_uiPosStart));
		tmp_uiPosStart = tmp_uiPosEnd + 1;
	} 

	return true;
}

void XString::mergeVec2Str(const std::vector<std::string> in_vec, const std::string in_strFlag, std::string & out_str)
{
	out_str.clear();

	// merge start
	for (std::vector<std::string>::size_type i = 0; i < in_vec.size(); ++i)
	{
		out_str += in_vec.at(i) + in_strFlag;
	}
}

XSPACE_END