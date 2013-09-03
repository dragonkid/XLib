#ifndef _XLOGGER_H_
#define _XLOGGER_H_

#include "xDefine.h"

XSPACE_BEGIN

class XLogger
{
    static XLogger * m_pLogger;
    XLogger()
    {

    }
    ~XLogger()
    {

    }
public:
    // Enable log.
    static XLogger * enable();
    // Disable log.
    static void disable();
};

XSPACE_END

#endif
