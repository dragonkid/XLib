#ifndef _XLOGGER_H_
#define _XLOGGER_H_

#include "xDefine.h"

XSPACE_BEGIN

class XLogger
{
    static XLogger * m_pLogger;
    XLogger();
    ~XLogger();
public:
    static XLogger * instance()
    {
        if ( NULL == m_pLogger )
        {
            m_pLogger = new XLogger();
        }
        return m_pLogger;
    }
};

XSPACE_END

#endif
