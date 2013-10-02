#include "LogTools.h"
#include "FileTools.h"
#include <sys/timeb.h>
#include <stdio.h>
#include <ctime>
#include <stdarg.h>
#include <sstream>

DTools::LogTools * g_pLogger = NULL;

TOOLSPACE_BEGIN

#ifdef WIN32
	DString LogTools::m_strLogPath = "C:\\logs\\";
#else
	DString LogTools::m_strLogPath = "/home/logs/";
#endif

bool LogTools::m_bEnable = false;

DOfstream LogTools::m_ofFileStream = DOfstream();

// 默认引入log类即为开启日志功能， 规避线程安全问题， 避免锁争夺。
// 静态实例初始化在程序开始时进入主函数之前就由主线程以单线程的方式完成了初始化。
LogTools * LogTools::m_pLogger = new LogTools();

// Get timestamp like 090413_00:04:19.812
DString LogTools::getTimeStamp()
{
	time_t now = time(NULL);
	struct tm * timeInfo = localtime(&now);
	char buf[10];
	strftime(buf, 10, "%H%M%S", timeInfo);
	DString tmp_strTime(buf);
	strftime(buf, 10, "%m%d%y", timeInfo);
	DString tmp_strDate(buf);
	timeb tb;
	ftime(&tb);
	sprintf(buf,"%03d",tb.millitm);
	return tmp_strDate + "_" + tmp_strTime + "." + buf;
}

LogTools::LogTools()
{
	m_ofFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	m_bLogHeader = true;
}

LogTools::~LogTools()
{
	if ( m_ofFileStream.is_open() )
	{
		m_ofFileStream.close();
	}
}

DString LogTools::getLogPath()
{
	return m_strLogPath;
}

LogTools * LogTools::enableLogger( const DString in_strLogPath )
{
	m_bEnable = true;
	if ( openLogFile(in_strLogPath) )
	{
		return m_pLogger;
	}
	return NULL;
}

void LogTools::disableLogger()
{
	m_bEnable = false;
	if ( NULL != m_pLogger )
	{	
		delete m_pLogger;
		m_pLogger = NULL;
	}
}

DString LogTools::composeLogHeader(const char * filename, const long linenum, const char * funcname)
{
	std::stringstream tmp_buf;
	DString tmp_strFILE(filename);
	DString tmp_strFilename = "";
#ifdef WIN32
	tmp_strFilename = FileTools::extractFilename(tmp_strFILE, '\\');
#else
	tmp_strFilename = FileTools::extractFilename(tmp_strFILE, '/');
#endif // WIN32
	tmp_buf << "[" << getTimeStamp() << "][" << tmp_strFilename << "][" << linenum << "][" << funcname << "] >> ";
	return tmp_buf.str();
}

LogTools & LogTools::appendLogHeader( const char * filename, const long linenum, const char * funcname )
{
	if ( m_bLogHeader )
	{
		if ( whetherExceedLimit(MAX_LOG_FILE_SIZE) )
		{
			// File size exceed limit. Need to open a new file.
			m_ofFileStream.close();
			(void)openLogFile(m_strLogPath);
		}
		m_ofFileStream << composeLogHeader(filename, linenum, funcname); 
		m_bLogHeader = false;
	}
	return (*this);
}

bool LogTools::openLogFile( const DString & in_strLogPath )
{
	// Use default file path when the path parameter is invalid.
	if ( false == FileTools::makeDirectory(in_strLogPath) )
	{
		FileTools::makeDirectory(m_strLogPath);
	}
	else
	{
		m_strLogPath = in_strLogPath;
	}
	DString tmp_strFilename = in_strLogPath + "debug_" + getTimeStamp() + ".log";
	try
	{
		m_ofFileStream.open(tmp_strFilename, std::ios::app);
	}
	catch (DOfstream::failure e)
	{
		LOG_TO_CONSOLE("", "Open file failed.");
		return false;
	}
	return true;
}

bool LogTools::whetherExceedLimit(DStreamOff in_uiSizeLimit )
{
	DStreamOff tmp_uiFileSize = m_ofFileStream.tellp();
	if ( tmp_uiFileSize > in_uiSizeLimit )
	{
		return true;
	}
	return false;
}

TOOLSPACE_END