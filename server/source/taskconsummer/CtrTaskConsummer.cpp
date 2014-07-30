#include "CtrTaskConsummer.h"
#include "../taskqueue/TaskQueue.h"
#include "../taskqueue/MsgTaskNode.h"
#include "../taskqueue/CtrTaskNode.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <memory.h>

extern CTaskQueue *g_msgTasks;
using namespace std;
int CCtrTaskConsummer::consume(CTaskNode *&task)
{
    int ret = MICRODUST_SUCCESS;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        return MICRODUST_FAIL;
    }

    struct sockaddr_in myAddr;
    myAddr.sin_family = AF_INET;
    myAddr.sin_port = htons(((CCtrTaskNode*)task)->getPort());
    myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    bzero(&(myAddr.sin_zero), 8);

    ret = bind(sockfd, (struct sockaddr *)&myAddr, sizeof(struct sockaddr));
    ASSERTSUCCESS(ret);

    ret = listen(sockfd, ((CCtrTaskNode*)task)->getConns());
    ASSERTSUCCESS(ret);

    struct sockaddr_in theirAddr;
    int sin_size = sizeof(struct sockaddr_in);
    int newfd = 0;

    while(m_stop)
    {
        sin_size = sizeof(struct sockaddr_in);
        memset(&theirAddr, 0, sin_size);
        newfd = accept(sockfd, (struct sockaddr*)&theirAddr, &sin_size);
        //创建一个任务
        CTaskNode *newTask = new CMsgTaskNode(newfd);
        g_msgTasks->addTask(newTask);
    }

    return MICRODUST_SUCCESS;
}

void CCtrTaskConsummer::stop(bool stop)
{
    this->m_stop = stop;
}