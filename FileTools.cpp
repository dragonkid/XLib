#include "FileTools.h"
#include <stdlib.h>
#include <direct.h>

TOOLSPACE_BEGIN

// 存在函数声明和定义两部分时，默认参数只可以在函数声明中设定一次
DString FileTools::extractDirectory(const DString & in_strPath, char in_cDelimiter)
{
    return in_strPath.substr(0, in_strPath.find_last_of(in_cDelimiter) + 1);
}

DString FileTools::extractFilename(const DString & in_strPath, char in_cDelimiter)
{
    return in_strPath.substr(in_strPath.find_last_of(in_cDelimiter) + 1);
}

DString FileTools::extractFileExtension(const DString & in_strPath, char in_cDelimiter)
{
    DString tmp_strFilename = extractFilename(in_strPath, in_cDelimiter);
    DString::size_type tmp_uiPos = tmp_strFilename.find_last_of('.');
    if ( DString::npos != tmp_uiPos )
        return tmp_strFilename.substr(tmp_uiPos);
    return DString();
}

DString FileTools::changeFileExtension(const DString & in_strPath, const DString & in_strExt, char in_cDelimiter)
{
    DString tmp_strFilename = extractFilename(in_strPath, in_cDelimiter);
    return extractDirectory(in_strPath, in_cDelimiter)
            + tmp_strFilename.substr(0, tmp_strFilename.find_last_of('.'))
            + in_strExt;
}

bool FileTools::makeDirectory( DString in_strDirectory )
{
	if (0 == chdir(in_strDirectory.c_str()))
	{
		return true;
	}
	DString tmp_strCmd = "";
#ifdef WIN32
	tmp_strCmd = "md " + in_strDirectory;
#else
	tmp_strCmd = "mkdir " + in_strDirectory;
#endif
	int tmp_iStatus = system(tmp_strCmd.c_str());
	if ( 0 != tmp_iStatus)
	{
		return false;
	}
	return true;
}

TOOLSPACE_END
