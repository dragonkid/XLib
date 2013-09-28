#include "LogTools.h"
#include "FileTools.h"
#include <sys/timeb.h>
#include <stdio.h>
#include <ctime>
#include <stdarg.h>

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
	sprintf(buf,"%d",tb.millitm);
	return tmp_strDate + "_" + tmp_strTime + "." + buf;
}

LogTools::LogTools()
{
	m_ofFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);
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


LogTools * LogTools::enableLogger( DString in_strLogPath )
{
	m_bEnable = true;
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
	LOG_TO_CONSOLE("File name: ", tmp_strFilename);
	try
	{
		m_ofFileStream.open(tmp_strFilename, std::ios::app);
	}
	catch (DOfstream::failure e)
	{
		LOG_TO_CONSOLE("", "Open file failed.");
	}

	return m_pLogger;
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

TOOLSPACE_END