#include "xLogger.h"

XSPACE_BEGIN

XLogger * XLogger::m_pLogger = NULL;

XLogger::XLogger()
{
    std::cout << "["
              << __FILE__
              << "|"
              << __LINE__
              << "]"
              << std::endl;
}

XSPACE_END
