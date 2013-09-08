#ifndef _FILETOOLS_H_
#define _FILETOOLS_H_

#include "ToolsDefine.h"

TOOLSPACE_BEGIN

class FileTools
{
    FileTools();
    ~FileTools();
public:
    // Function:    Returns everything, including the trailing path separator,
    //              except the filename part of the path.
    // Example:     "/foo/bar/baz.txt"  =>  "/foo/bar/"
    static DString extractDirectory(const DString & in_strPath, char in_cDelimiter = '/');

    // Function:    Returns only the filename part of the path.
    // Example:     "/foo/bar/baz.txt"  =>  "baz.txt"
    static DString extractFilename(const DString & in_strPath, char in_cDelimiter = '/');

    // Function:    Returns the file's extension, if any. The period is
    //              considered part of the extension.
    // Example:     "/foo/bar/baz.txt"  =>  ".txt"
    //              "/foo/bar/baz"      =>  ""
    static DString extractFileExtension(const DString & in_strPath, char in_cDelimiter = '/');

    // Function:    Modified the filename's extension. The period is considered
    //              part of the extension.
    // Example:     "/foo/bar/baz.txt", ".dat"  =>  "/foo/bar/baz.dat"
    //              "/foo/bar/baz.txt", ""      =>  "/foo/bar/baz"
    //              "/foo/bar/baz", ".txt"      =>  "/foo/bar/baz.txt"
    static DString changeFileExtension(const DString & in_strPath, const DString & in_strExt,
                                       char in_cDelimiter = '/');
};

TOOLSPACE_END

#endif
