#include <iterator>
#include "ThreadPool.h"
#include "../../include/Microdust_def.h"

using namespace std;
CThreadPool::CThreadPool(CTaskQueue *jobs, CTaskConsummer *consummer)
{
    CThreadPool(jobs, consummer, 1, 10);
}

CThreadPool::CThreadPool(CTaskQueue *jobs, CTaskConsummer *consummer, int min, int max):m_minCnt(min),m_maxCnt(max)
{
    m_workThread.resize(m_minCnt);
    m_pJobs = jobs;
    m_consummer = consummer;
    m_exit = false;
}

CThreadPool::~CThreadPool()
{
}

int CThreadPool::init()
{
    int ret = MICRODUST_SUCCESS;
    vector<pthread_t>::iterator it = m_workThread.begin();
    for(; it < m_workThread.end(); it++)
    {
        ret = pthread_create(&(*it), NULL, Work, NULL); 
        
    }

    ret = pthread_create(&m_ctrThread, NULL, Control, NULL); 
}

/*
工作线程
*/
void* CThreadPool::Work(void *args)
{
    CThreadPool* pPool = (CThreadPool*)args;
    if (pPool->m_pJobs == MICRODUST_NULL || pPool->m_consummer == MICRODUST_NULL)
    {
        return NULL;
    }
    while(!pPool->m_exit)
    {
        CTaskNode *pTask = pPool->m_pJobs->getTask();
        if (pTask == MICRODUST_NULL)
        {
            continue;
        }

        pPool->m_consummer->consume(pTask);
    }

    return MICRODUST_NULL;
}

/*
   线程池管理线程
*/
void* CThreadPool::Control(void *args)
{
    return MICRODUST_NULL;
    //todo
}

void CThreadPool::exit(bool exit)
{
    m_exit = exit;
}

