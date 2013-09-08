#include "StringTools.h"
#include <cctype>
#include <algorithm>

static bool isValidIPPart(const DString & in_str)
{
    if ( in_str.empty()
        || !DTools::StringTools::isAllDigit(in_str)
        || ((in_str.length() > 1) && (in_str.at(0) == '0')) )
    {
        return false;
    }
    int tmp_i = atoi(in_str.c_str());
    if ( (tmp_i < 0) || (tmp_i > 255) )
    {
        return false;
    }
    return true;
}

TOOLSPACE_BEGIN

bool StringTools::startWith(const DString in_str, const DString in_strFlag)
{
    if ( in_strFlag.empty() || (in_str.length() < in_strFlag.length()) )
    {
        return false;
    }

    return (0 == in_str.find(in_strFlag))? true: false;
}

bool StringTools::endWith(const DString in_str, const DString in_strFlag)
{
    if ( in_strFlag.empty() || (in_str.length() < in_strFlag.length()) )
    {
        return false;
    }

    size_t tmp_uiPos = in_str.length() - in_strFlag.length();

    return (tmp_uiPos == in_str.find(in_strFlag, tmp_uiPos));
}

bool StringTools::splitStr2Vec(const DString in_str, const DString in_strFlag,	std::vector<DString>& out_vec)
{
    out_vec.clear();

    if ( in_str.empty() || ("" == in_str) || (in_strFlag.length() != 1) )
    {
        return false;
    }

    DString tmp_strTmp = in_str;
    // did not find in_strFlag at the end of in_str
    if ( in_str.find_last_of(in_strFlag) != (in_str.length() - in_strFlag.length()) )
    {
        tmp_strTmp.append(in_strFlag);
    }

    // start to divide
    DString::size_type tmp_uiPosStart = 0;
    DString::size_type tmp_uiPosEnd = 0;
    while ( DString::npos != (tmp_uiPosEnd = tmp_strTmp.find(in_strFlag, tmp_uiPosStart)) )
    {
        out_vec.push_back(tmp_strTmp.substr(tmp_uiPosStart, tmp_uiPosEnd - tmp_uiPosStart));
        tmp_uiPosStart = tmp_uiPosEnd + 1;
    }

    return true;
}

void StringTools::mergeVec2Str(const std::vector<DString> in_vec, const DString in_strFlag, DString & out_str)
{
    out_str.clear();

    // merge start
    for (std::vector<DString>::size_type i = 0; i < in_vec.size(); ++i)
    {
        out_str += in_vec.at(i) + in_strFlag;
    }
}

void StringTools::replaceAWithB(DString & inout_str, const DString in_strA, const DString in_strB )
{
    DString::size_type tmp_uiPos = 0;

    while (DString::npos != (tmp_uiPos = inout_str.find(in_strA, tmp_uiPos)))
    {
        inout_str.replace(tmp_uiPos, in_strA.length(), in_strB);
        tmp_uiPos += (in_strB.length() - in_strA.length()) + 1;
    }
}

bool StringTools::subStrS2E(const DString & in_str, const DString & in_strStartFlag, const DString & in_strEndFlag, DString & out_str )
{
    out_str.clear();

    DString::size_type tmp_uiStartPos = 0;
    DString::size_type tmp_uiEndPos = 0;
    if ( DString::npos == (tmp_uiStartPos = in_str.find(in_strStartFlag)) )
    {
        return false;
    }
    else
    {
        tmp_uiStartPos += in_strStartFlag.length();
    }
    if ( DString::npos == (tmp_uiEndPos = in_str.find(in_strEndFlag, tmp_uiStartPos)) )
    {
        return false;
    }

    out_str = in_str.substr(tmp_uiStartPos, tmp_uiEndPos - tmp_uiStartPos);
    return true;
}

bool StringTools::subStrE2S(const DString & in_str, const DString & in_strStartFlag, const DString & in_strEndFlag, DString & out_str )
{
    out_str.clear();

    DString::size_type tmp_uiStartPos = 0;
    DString::size_type tmp_uiEndPos = 0;
    if ( (DString::npos == (tmp_uiEndPos = in_str.rfind(in_strEndFlag)))
            || (0 == tmp_uiEndPos))
    {
        return false;
    }
    if ( DString::npos == (tmp_uiStartPos = in_str.rfind(in_strStartFlag, tmp_uiEndPos - 1)) )
    {
        return false;
    }
    else
    {
        tmp_uiStartPos += in_strStartFlag.length();
    }

    out_str = in_str.substr(tmp_uiStartPos, tmp_uiEndPos - tmp_uiStartPos);
    return true;
}

bool StringTools::subStrWide(const DString & in_str, const DString & in_strStartFlag, const DString & in_strEndFlag, DString & out_str )
{
    out_str.clear();

    DString::size_type tmp_uiStartPos = 0;
    DString::size_type tmp_uiEndPos = 0;
    if ( DString::npos == (tmp_uiStartPos = in_str.find(in_strStartFlag)) )
    {
        return false;
    }
    if ( DString::npos == (tmp_uiEndPos = in_str.rfind(in_strEndFlag))
            || (tmp_uiEndPos <= tmp_uiStartPos))
    {
        return false;
    }

    tmp_uiStartPos += in_strStartFlag.length();
    out_str = in_str.substr(tmp_uiStartPos, tmp_uiEndPos - tmp_uiStartPos);
    return true;
}

bool StringTools::isAllDigit(const DString & in_str)
{
    if (in_str.empty()) return false;
    DString::const_iterator tmp_iterFirst = in_str.begin();
    while ( tmp_iterFirst != in_str.end())
    {
        if (!isdigit(*tmp_iterFirst)) return false;
        ++tmp_iterFirst;
    }
    return true;
}

bool StringTools::isAllAlpha(const DString & in_str)
{
    if (in_str.empty()) return false;
    DString::const_iterator tmp_iterFirst = in_str.begin();
    while ( tmp_iterFirst != in_str.end())
    {
        if (!isalpha(*tmp_iterFirst)) return false;
        ++tmp_iterFirst;
    }
    return true;
}

bool StringTools::isValidIPAddress(const DString & in_str)
{
    std::vector<DString> tmp_vecIPPart;
    DString::size_type tmp_uiStartPos = 0;
    DString::size_type tmp_uiEndPos = 0;
    do
    {
        tmp_uiEndPos = in_str.find(".", tmp_uiStartPos);
        tmp_vecIPPart.push_back(in_str.substr(tmp_uiStartPos, tmp_uiEndPos - tmp_uiStartPos));
        tmp_uiStartPos = tmp_uiEndPos + 1;
    } while ( DString::npos != tmp_uiEndPos );

    if ( tmp_vecIPPart.size() != 4 ) return false;
    for (std::vector<DString>::size_type i = 0; i < tmp_vecIPPart.size(); ++i)
    {
        if ( !isValidIPPart(tmp_vecIPPart.at(i)) ) return false;
    }
    return true;
}

TOOLSPACE_END
