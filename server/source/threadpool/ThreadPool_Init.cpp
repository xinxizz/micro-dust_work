#include "../../include/Microdust_def.h"
#include "ThreadPool.h"
#include "../taskqueue/TaskQueue.h"
static CThreadPool *g_ctrThreads = MICRODUST_NULL;
static CThreadPool *g_msgThreads = MICRODUST_NULL;
static CThreadPool *g_rslThreads = MICRODUST_NULL;

extern CTaskQueue* g_ctrTasks;
extern CTaskQueue* g_msgTasks;
extern CTaskQueue* g_rslTasks;

void threadPool_init()
{
    g_ctrThreads = new CThreadPool(g_ctrTasks, MICRODUST_NULL);
    g_msgThreads = new CThreadPool(g_msgTasks, MICRODUST_NULL);
    g_rslThreads = new CThreadPool(g_rslTasks, MICRODUST_NULL);
}

void threadPool_uninit()
{
    delete g_ctrThreads;
    delete g_msgThreads;
    delete g_rslThreads;
}

