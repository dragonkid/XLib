#include "xTime.h"

XSPACE_BEGIN

DBool XTime::getLocalTZOffset(DFloat8 & out_iTZOffset)
{
    struct tm tmp_tmBase;
    tmp_tmBase.tm_year = 1970 - 1900;   // years since 1900
    tmp_tmBase.tm_mon = 1 - 1;          // months since January	0-11
    tmp_tmBase.tm_mday = 1;
    tmp_tmBase.tm_hour = 0;
    tmp_tmBase.tm_min = 0;
    tmp_tmBase.tm_sec = 0;
    time_t tmp_tUTCTime = 0;
    time_t tmp_tLocalTime = 0;

#ifdef _BSD_SOURCE
    // Thread safe
    if ( NULL == localtime_r(&tmp_tLocalTime, &tmp_tmBase))
    {
        return false;
    }
    out_iTZOffset = tmp_tmBase.tm_gmtoff;
#else
    // incomplete
    out_iTZOffset = 0;
#endif
    return true;
}

XSPACE_END
