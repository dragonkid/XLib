#ifndef _TOOLSDEFINE_H_
#define _TOOLSDEFINE_H_

#include <string>
#include <fstream>

#define TOOLSPACE_BEGIN             namespace DTools{
#define TOOLSPACE_END               }

// Convert __LINE__ to string by macro.
#define DEBUGLOG_LINE(x) DEBUGLOG_LINE2(x)
#define DEBUGLOG_LINE2(x) #x

typedef unsigned long long			flowid_type;

typedef std::string                 DString;
typedef int                         DInt4;
typedef double                      DFloat8;
typedef long long                   DTime_t;
typedef std::ofstream				DOfstream;

#endif
