#include "../../include/Microdust_def.h"
#include "TaskQueue.h"
using namespace std;
CTaskQueue::CTaskQueue()
{
    
}

CTaskQueue::CTaskQueue(int n)
{
    m_taskqueue.resize(n);
}


int CTaskQueue::init()
{
    int ret = MICRODUST_SUCCESS;
    ret = pthread_mutex_init(&m_mutex, NULL);
    ASSERTSUCCESS(ret);
    m_status = MICRODUST_TRUE;
    return ret;
}

CTaskNode* CTaskQueue::getTask()
{
    CTaskNode *task = MICRODUST_NULL;
    pthread_mutex_lock(&m_mutex);
    if (!m_taskqueue.empty())
    {
        task = (CTaskNode *)m_taskqueue.front();    
    }
    pthread_mutex_unlock(&m_mutex);

    return task;
}

int CTaskQueue::addTask(CTaskNode* &task)
{
    int size = 0;
    pthread_mutex_lock(&m_mutex);
    m_taskqueue.push_back(task);
    size = m_taskqueue.size();
    pthread_mutex_unlock(&m_mutex);

    return size;
}


