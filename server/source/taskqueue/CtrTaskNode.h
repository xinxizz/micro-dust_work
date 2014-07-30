#ifndef DEF_CCtrTASKNODE
#define DEF_CCtrTASKNODE
#include "TaskNode.h"
class CCtrTaskNode : public CTaskNode
{
private:
    ushort m_listenPort;
    ushort m_connLimit;
public:
    CCtrTaskNode();
    CCtrTaskNode(int port,int limit);
    ushort getPort();
    ushort getConns();
};
#endif
