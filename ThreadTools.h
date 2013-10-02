#ifndef _THREADTOOLS_H_
#define _THREADTOOLS_H_

#include "ToolsDefine.h"

TOOLSPACE_BEGIN

#ifdef WIN32  //define the macro for Win32 thread

#include <windows.h>
#include <process.h>  
/*************  mutex (use CRITICAL_SECTION in windows) ***************/
#define THREAD_MUTEX             CRITICAL_SECTION
#define	INITIALIZE_MUTEX(mutex)  InitializeCriticalSection(mutex)
#define	DESTROY_MUTEX            DeleteCriticalSection
#define	LOCK_MUTEX               EnterCriticalSection
#define UNLOCK_MUTEX             LeaveCriticalSection
#define THREAD_HANDLE            unsigned long
/**********************************************************************/

typedef unsigned int (__stdcall * THREAD_FUN_TYPE)(void *);

#else  //define the macro for POSIX thread

#include <pthread.h>
/*************  mutex (use mutex in Unix like) ***********************/
#define THREAD_MUTEX             pthread_mutex_t
#define INITIALIZE_MUTEX(mutex)  pthread_mutex_init(mutex, NULL)   
#define DESTROY_MUTEX            pthread_mutex_destroy
#define LOCK_MUTEX               pthread_mutex_lock
#define UNLOCK_MUTEX             pthread_mutex_unlock
#define THREAD_HANDLE            pthread_t
/**********************************************************************/

typedef void *( * THREAD_FUN_TYPE)(void *);

#endif  //WIN32

class ThreadTools
{
public:
	/***********************************************************************
	**	Function:	This function is used to create a new thread. The new thread's
					function has the form as follows:
						int (* pThreadFun) (void *) 
						(one argument which is void * and return an integer type data)
	**	Input:		pThreadFun -- the address of function to create a new thread
					pParam -- the parameter of the new thread
	**  Return:		The handle of the new thread
	************************************************************************/
	static THREAD_HANDLE CREATE_THREAD(int (* pThreadFun)( void * ),  void * pParam);

	/***********************************************************************
	**  Function:	This function is used to end a thread. This function is
					usually used at the end of the Thread function.
	************************************************************************/
	static void END_THREAD();

	/***********************************************************************
	**  Function:	This function is used to close the handle of a thread.
	**  input:		hThread -- the handle of the thread.
	************************************************************************/
	static void CLOSE_THREAD(THREAD_HANDLE hThread);

	/***********************************************************************
	**  Function:	This function is used to wait for another thread.
					So the main thread used this function will suspend
					until the waiting thread finished.
	**  Input:		hThread -- the handle of waiting thread.
	************************************************************************/
	static void WAIT_THREAD(THREAD_HANDLE hThread);
protected:
private:
};	// ThreadTools

TOOLSPACE_END

#endif