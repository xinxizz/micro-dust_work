#include "../../include/Microdust_def.h"
#include "TaskQueue.h"

CTaskQueue *g_ctrTasks = MICRODUST_NULL;
CTaskQueue *g_msgTasks = MICRODUST_NULL;
CTaskQueue *g_rslTasks = MICRODUST_NULL;

CTaskQueue *taskQueue_factory(int type)
{
    CTaskQueue *ret = MICRODUST_NULL;
    switch(type)
    {
        case 1:
            ret = g_ctrTasks;
            break;
        case 2:
            ret = g_msgTasks;
            break;
        case 3:
            ret = g_rslTasks;
            break;
        default:
            break;
    }
    return ret;
}

void taskQueue_init()
{
    g_ctrTasks = new CTaskQueue();
    g_msgTasks = new CTaskQueue();
    g_rslTasks = new CTaskQueue();
}


