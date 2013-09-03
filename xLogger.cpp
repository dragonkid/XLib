#include "xLogger.h"
#include <sys/timeb.h>
#include <stdio.h>

// Get timestamp like 00:04:19.812 09/04/13
DString timeStamp()
{
    time_t now = time(NULL);
    struct tm * timeInfo = localtime(&now);
    char buf[10];
    strftime(buf, 10, "%X", timeInfo);
    DString tmp_strTime(buf);
    strftime(buf, 10, "%x", timeInfo);
    DString tmp_strDate(buf);
    timeb t;
    ftime(&t);
    sprintf(buf,"%d",t.millitm);
    return tmp_strTime + "." + buf + " " + tmp_strDate;
}

XSPACE_BEGIN

XLogger * XLogger::m_pLogger = NULL;

XLogger * XLogger::enable()
{
    if ( NULL == m_pLogger )
    {
        m_pLogger = new XLogger();
    }
    return m_pLogger;
}

void XLogger::disable()
{
    if ( NULL != m_pLogger )
    {
        delete m_pLogger;
        m_pLogger = NULL;
    }
}

XSPACE_END
