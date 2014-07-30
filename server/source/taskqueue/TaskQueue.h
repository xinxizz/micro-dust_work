#ifndef DEF_CTASKQUEUE
#define DEF_CTASKQUEUE
#include <list>
#include <pthread.h>
#include "TaskNode.h"

class CTaskQueue
{
private:
    pthread_mutex_t m_mutex; 
    int m_status;
    std::list<CTaskNode*> m_taskqueue;
public:
    CTaskQueue();
    CTaskQueue(int n);
    ~CTaskQueue();
    int addTask(CTaskNode* &task);
    CTaskNode* getTask();
    int init();
};

#endif
