#include "TaskNode.h"
#include "RslTaskNode.h"

CRslTaskNode::CRslTaskNode(int sock) : m_sockfd(sock)
{
}

CRslTaskNode::~CRslTaskNode()
{
}

int CRslTaskNode::getSockfd()
{
    return m_sockfd;
}

