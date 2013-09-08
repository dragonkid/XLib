#include "LogTools.h"
#include <sys/timeb.h>
#include <stdio.h>

// Get timestamp like 00:04:19.812 09/04/13
static DString timeStamp()
{
    time_t now = time(NULL);
    struct tm * timeInfo = localtime(&now);
    char buf[10];
    strftime(buf, 10, "%X", timeInfo);
    DString tmp_strTime(buf);
    strftime(buf, 10, "%x", timeInfo);
    DString tmp_strDate(buf);
    timeb tb;
    ftime(&tb);
    sprintf(buf,"%d",tb.millitm);
    return tmp_strTime + "." + buf + " " + tmp_strDate;
}

TOOLSPACE_BEGIN

// 默认引入log类即为开启日志功能， 规避线程安全问题， 避免锁争夺。
// 静态实例初始化在程序开始时进入主函数之前就由主线程以单线程的方式完成了初始化。
LogTools * LogTools::m_pLogger = new LogTools();

void LogTools::setLogType(LOG_TYPE in_eLogType)
{
    m_eLogType = in_eLogType;
}

const LOG_TYPE LogTools::getLogType() const
{
    return m_eLogType;
}

void LogTools::setPath( const DString & in_strPath )
{
	m_strPath = in_strPath;
}

const DString LogTools::getPath() const
{
	return m_strPath;
}

TOOLSPACE_END
