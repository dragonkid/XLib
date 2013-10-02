#include "ThreadTools.h"
#include "LogTools.h"

TOOLSPACE_BEGIN

#ifdef WIN32  //define the macro for Win32 thread

THREAD_HANDLE ThreadTools::CREATE_THREAD(int (* pThreadFun)( void * ),  void * pParam)
{
	//uintptr_t tmp_res = _beginthreadex(NULL, 0, (THREAD_FUN_TYPE) pThreadFun, pParam, NULL, NULL);
	//LOG_TO_CONSOLE("tmp_res", tmp_res);
	return _beginthreadex(NULL, 0, (THREAD_FUN_TYPE) pThreadFun, pParam, NULL, NULL);
}

void ThreadTools::END_THREAD()
{
	_endthreadex(0);
}

void ThreadTools::CLOSE_THREAD(THREAD_HANDLE hThread)
{
	CloseHandle((HANDLE *) hThread);
}

void ThreadTools::WAIT_THREAD(THREAD_HANDLE hThread)
{
	WaitForSingleObject((HANDLE*)hThread, INFINITE);
}

#else  //define the macro for POSIX thread

THREAD_HANDLE ThreadTools::CREATE_THREAD(int (* pThreadFun)( void * ),  void * pParam)
{
	pthread_t threadID;
	pthread_create(&threadID, NULL, (THREAD_FUN_TYPE)pThreadFun, pParam);
	return threadID;
}

void ThreadTools::END_THREAD()
{
	pthread_exit(0);
}

void ThreadTools::CLOSE_THREAD(THREAD_HANDLE hThread)
{

}

void ThreadTools::WAIT_THREAD(THREAD_HANDLE hThread)
{
	void * retval;
	pthread_join(hThread, &retval);
}

#endif // WIN32

TOOLSPACE_END