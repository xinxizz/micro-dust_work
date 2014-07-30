#include <sys/types.h>
#include <sys/socket.h>
#include "CtrTaskNode.h"

CCtrTaskNode::CCtrTaskNode()
{

}

CCtrTaskNode::CCtrTaskNode(int port, int limit) : m_listenPort(port), m_connLimit(limit)
{

}

ushort CCtrTaskNode::getPort()
{
    return m_listenPort;
}

ushort CCtrTaskNode::getConns()
{
    return m_connLimit;
}
