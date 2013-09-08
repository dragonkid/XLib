#ifndef _LOGTOOLS_H_
#define _LOGTOOLS_H_

#include "ToolsDefine.h"
#include <iostream>

TOOLSPACE_BEGIN

// A very simple log tool
#define LOG_TO_CONSOLE(explanation, value)\
    std::cout << (explanation) << (output) << std::endl;

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
    LOG_LEVEL       m_eLogLevel;    // Info default
    // Default value:
    // Linux    /home/LogFiles
    // Windows  C:\LogFiles
    DString         m_strFilePath;

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
    void setLogType(LOG_TYPE in_eLogType);
    // Get log type.
    const LOG_TYPE getLogType() const;
    // Set log level.
    void setLogLevel(LOG_LEVEL in_eLogLevel);
    // Get log level.
    const LOG_LEVEL getLogLevel() const;

};

TOOLSPACE_END

#endif
