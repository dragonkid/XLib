#ifndef _LOGTOOLS_H_
#define _LOGTOOLS_H_

#include "ToolsDefine.h"
#include <iostream>

TOOLSPACE_BEGIN

// A simple debug tool.
#define LOG_TO_CONSOLE(explanation, value)\
    std::cout << (explanation) << (value) << std::endl;

// A complete debug tool.
class LogTools
{
	static LogTools *	m_pLogger;
	static DOfstream	m_ofFileStream;
	// Initialize the log tool.
	// Default value:
	// Linux    "/home/logs"
	// Windows  "C:\\logs\\"
	static DString		m_strLogPath;
	static bool			m_bEnable;
	bool				m_bLogHeader;

    LogTools();
    LogTools(const LogTools &);
    LogTools & operator = (const LogTools &);
    virtual ~LogTools();
	// Get timestamp.
	static DString getTimeStamp();
	// Compose log header.
	DString composeLogHeader(char * filename, long linenum, char * funcname);
public:
	// Get log file path.
	DString getLogPath();
	// Enable the logger.
#ifdef WIN32
	static LogTools * enableLogger(const DString in_strLogPath = "C:\\logs\\");
#else
	static LogTools * enableLogger(const DString in_strLogPath = "/home/logs/");
#endif
	// Disable the logger.
	static void disableLogger();
	// Write log to log file.
	template<typename T>
	LogTools & operator<<(const T & value)
	{
		if ( m_bEnable )
		{
			m_ofFileStream << value;
		}
		return (*this);
	}
	// End write log to log file.
	LogTools & operator<<(std::ostream & (*_Pfn)(std::ostream &))
	{
		if ( m_bEnable )
		{
			(*_Pfn)(m_ofFileStream);
			m_bLogHeader = true;
		}
		return (*this);
	}
	// Write debug message to log file.
	LogTools & appendLogHeader(char * filename, long linenum, char * funcname);
};

TOOLSPACE_END

#endif
