#include "../../include/Microdust_def.h"
#include "../common/Microdust_error.h"
#include "../taskqueue/MsgTaskNode.h"
#include "MsgTaskConsummer.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <memory.h>

int CMsgTaskConsummer::consume(CTaskNode *&task)
{
    int sockfd = ((CMsgTaskNode*)task)->getSocket();
    
    if (-1 == sockfd || m_msgCenter == MICRODUST_NULL)
    {
        return MDJSS_TASK_UNINIT_ERR;
    }
    char buf[TASK_REQUEST_HEAD_LEN];
    memset(buf, 0, TASK_REQUEST_HEAD_LEN);
    //TLV格式 6个字节T L
    if (TASK_REQUEST_HEAD_LEN != recv(sockfd, buf, TASK_REQUEST_HEAD_LEN, 0))
    {
        return MDJSS_TASK_REQUEST_FORMAT_ERR;
    }
    unsigned short cmd = ntohs(*((unsigned short*)(void*)buf));
    unsigned short len = ntohs(*((unsigned short*)(void*)(buf + 2)));

    char *data = new char[len + 1];
    memset(data, 0, len + 1);
    
    if (recv(sockfd, data, len, 0) < len)
    {
        return MDJSS_TASK_REQUEST_FORMAT_ERR;
    }
    task->setData(data, len);

    m_msgCenter->dispatch(cmd, task);
    delete task;
}
