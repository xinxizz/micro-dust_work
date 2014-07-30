#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include "RslTaskConsummer.h"
#include "../taskqueue/RslTaskNode.h"
#include "../../include/Microdust_def.h"
int CRslTaskConsummer::consume(CTaskNode *&task)
{
    int sockfd = ((CRslTaskNode*)task)->getSockfd();
    char* data = task->getData();
    uint   size = task->getSize();
    
    send(sockfd, data, size, 0);
    close(sockfd);
    delete task;

    return MICRODUST_SUCCESS;
}