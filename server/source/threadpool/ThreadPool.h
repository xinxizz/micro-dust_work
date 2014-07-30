#ifndef DEF_CTHREADPOOL
#define DEF_CTHREADPOOL
#include <vector>
#include <pthread.h>
#include "../taskqueue/TaskQueue.h"
#include "../taskconsummer/TaskConsummer.h"

typedef void*(*PF_THREAD_FUN)(void*);

class CThreadPool{
private:
    bool m_exit;
    int m_minCnt;
    int m_maxCnt;
    std::vector<pthread_t> m_workThread;
    pthread_t m_ctrThread;
    CTaskQueue *m_pJobs;
    CTaskConsummer *m_consummer;
    
 private:
    static void *Work(void *args);
    static void *Control(void *args);
public:
    CThreadPool(CTaskQueue *jobs, CTaskConsummer *consummer);
    CThreadPool(CTaskQueue *jobs, CTaskConsummer *consummer,int min, int max);
    ~CThreadPool();
    void exit(bool exit);
    int init();
};
#endif
