#include "xFile.h"

XSPACE_BEGIN

// 存在函数声明和定义两部分时，默认参数只可以在函数声明中设定一次
DString FileOperate::extractDirectory(const DString & in_strPath, char in_cDelimiter)
{
    return in_strPath.substr(0, in_strPath.find_last_of(in_cDelimiter) + 1);
}

DString FileOperate::extractFilename(const DString & in_strPath, char in_cDelimiter)
{
    return in_strPath.substr(in_strPath.find_last_of(in_cDelimiter) + 1);
}

DString FileOperate::extractFileExtension(const DString & in_strPath, char in_cDelimiter)
{
    DString tmp_strFilename = extractFilename(in_strPath, in_cDelimiter);
    DString::size_type tmp_uiPos = tmp_strFilename.find_last_of('.');
    if ( DString::npos != tmp_uiPos )
        return tmp_strFilename.substr(tmp_uiPos);
    return DString();
}

DString FileOperate::changeFileExtension(const DString & in_strPath, const DString & in_strExt, char in_cDelimiter)
{
    DString tmp_strFilename = extractFilename(in_strPath, in_cDelimiter);
    return extractDirectory(in_strPath, in_cDelimiter)
            + tmp_strFilename.substr(0, tmp_strFilename.find_last_of('.'))
            + in_strExt;
}

XSPACE_END
