#ifndef _XTIME_H_
#define _XTIME_H_

#include "xDefine.h"

XSPACE_BEGIN

class XTime
{
public:
    // function:        get local timezone offset
    // in:              none
    // out:             out_iTZOffset(timezone offset)
    // return:          bool
    //                  true:   get success
    //                  false:  get failed
    // Linux version complete. Tested.
    // Windows version complete. Did not test and verify.
    static bool getLocalTZOffset(DFloat8 & out_iTZOffset);

    // function:        set zoneinfo database path
    // in:              in_strPath(zoneinfo path of the OS)
    // out:             none
    // return:          void
    static void setZoneinfoPath(const DString & in_strPath);

    // function:        Get timezone offset by timezone name.
    // in:              in_strZoneName
    // out:             out_iTZOffset
    // return:          bool
    //                  true:   get success
    //                  false:  get failed
    // example:         Asia/Shanghai   => 28800
    // incomplete
    static bool getTZOffsetByZonename(
        const DString & in_strZoneName,
        DFloat8 & out_iTZOffset
        );
protected:
private:
    static DString m_strZoneInfo;
};	// class XTime

XSPACE_END

#endif
