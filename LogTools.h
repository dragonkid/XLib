#ifndef _LOGTOOLS_H_
#define _LOGTOOLS_H_

#include "ToolsDefine.h"
#include <iostream>
#include <ctime>

TOOLSPACE_BEGIN

// A simple debug tool.
#define LOG_TO_CONSOLE(explanation, value)\
    std::cout << (explanation) << (value) << std::endl;

typedef enum _LOG_TYPE
{
    CONSOLE      = 0,
    FILE         = 1,
    ALL
}LOG_TYPE;

typedef enum _LOG_LEVEL
{
    INFO          = 0,
    WARNING       = 1,
    ERROR         = 2,
    END
}LOG_LEVEL;

class LogTools
{
    LOG_TYPE        m_eLogType;     // ALL defaule
    // Default value:
    // Linux    /home/LogFiles
    // Windows  C:\LogFiles
    DString         m_strPath;

    LogTools()
    {

    }
    LogTools(const LogTools &);
    LogTools & operator = (const LogTools &);
    virtual ~LogTools()
    {

    }
public:
    static LogTools *    m_pLogger;

    // Set log type.
    void setLogType(const LOG_TYPE in_eLogType);
    // Get log type.
    const LOG_TYPE getLogType() const;
	// Set path.
	void setPath(const DString &);
	// Get path.
	const DString getPath() const;
};

TOOLSPACE_END

#endif
