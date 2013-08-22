#ifndef _XTIME_H_
#define _XTIME_H_

#include "xDefine.h"

XSPACE_BEGIN

class XTime
{
public:
    // function:        get local timezone offset
    // in:              none
    // out:             DInt4(timezone offset)
    // return:          DBool
    //                  true:   get success
    //                  false:  get failed
    static DBool getLocalTZOffset(DFloat8 & out_iTZOffset);

protected:
private:
};	// class XTime

XSPACE_END

#endif
