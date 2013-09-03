#include "xTime.h"

#ifdef WIN32
// Should be built with /clr
#using <mscorlib.dll>
#endif

XSPACE_BEGIN

DString XTime::m_strZoneInfo = "";

bool XTime::getLocalTZOffset(DFloat8 & out_iTZOffset)
{
	out_iTZOffset = 0;
	bool tmp_bFlag = false;

#ifdef _BSD_SOURCE
    struct tm tmp_tmBase;
    tmp_tmBase.tm_year = 1970 - 1900;   // years since 1900
    tmp_tmBase.tm_mon = 1 - 1;          // months since January	0-11
    tmp_tmBase.tm_mday = 1;
    tmp_tmBase.tm_hour = 0;
    tmp_tmBase.tm_min = 0;
    tmp_tmBase.tm_sec = 0;
    time_t tmp_tLocalTime = 0;
    // Thread safe
    tmp_bFlag = true;
    if ( NULL == localtime_r(&tmp_tLocalTime, &tmp_tmBase))
    {
        return false;
    }
    out_iTZOffset = tmp_tmBase.tm_gmtoff;
#endif

#ifdef WIN32
    tmp_bFlag = true;
    using namespace System;
	using namespace Runtime::InteropServices;

	DateTime tmp_dtCurrentDate = DateTime::Now;
	TimeZone^ tmp_tzLocalZone = TimeZone::CurrentTimeZone;
	out_iTZOffset = tmp_tzLocalZone->GetUtcOffset(tmp_dtCurrentDate).TotalSeconds;
#endif

    return tmp_bFlag;
}

void XTime::setZoneinfoPath(const DString & in_strPath)
{
    m_strZoneInfo = in_strPath;
}

bool XTime::getTZOffsetByZonename( const DString & in_strZoneName, DFloat8 & out_iTZOffset )
{
// TODO (dragonkid#1#): This Function will be complete later.
    return true;
}

DTime_t XTime::getMilliTime()
{
    timeb t;
    ftime(&t);
    return (1000 * static_cast<DTime_t>(t.time) + t.millitm);
}

XSPACE_END
