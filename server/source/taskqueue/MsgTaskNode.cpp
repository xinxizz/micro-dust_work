#include "TaskNode.h"
#include "MsgTaskNode.h"

CMsgTaskNode::CMsgTaskNode() : m_sockfd(-1)
{   
}

CMsgTaskNode::CMsgTaskNode(int sockfd) : m_sockfd(sockfd)
{
}

CMsgTaskNode::~CMsgTaskNode()
{
}

void CMsgTaskNode::setCmd(ushort cmd)
{
   this->m_cmd = cmd;
}

int CMsgTaskNode::getSocket()
{
    return m_sockfd;
}