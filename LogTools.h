#ifndef _LOGTOOLS_H_
#define _LOGTOOLS_H_

#include "ToolsDefine.h"
#include <iostream>

TOOLSPACE_BEGIN

// A simple debug tool.
#define LOG_TO_CONSOLE(explanation, value)\
    std::cout << (explanation) << (value) << std::endl;

// A complete debug tool.

// Macros of log.
#define DLOGGER_INIT g_pLogger = DTools::LogTools::enableLogger();
#define DLOGGER (*g_pLogger).appendLogHeader(__FILE__, __LINE__, __FUNCTION__)
#define DLOGGER_END g_pLogger->disableLogger();

#define MAX_LOG_FILE_SIZE (30 * 1000 * 1000)	// 30M

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
	flowid_type			m_uiFlowID;

    LogTools();
    LogTools(const LogTools &);
    LogTools & operator = (const LogTools &);
    virtual ~LogTools();
	// Get timestamp.
	static DString getTimeStamp();
	// Compose log header.
	DString composeLogHeader(const char * filename, const long linenum, const char * funcname);
	// Open log file.
	static bool openLogFile(const DString & in_strLogPath);
	// Whether log file size exceed limit.
	bool whetherExceedLimit(DStreamOff in_uiSizeLimit);
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
	LogTools & appendLogHeader(const char * filename, const long linenum, const char * funcname);
};

TOOLSPACE_END

extern DTools::LogTools * g_pLogger;

#endif
