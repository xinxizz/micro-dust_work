#ifndef DEF_CMSGTASKNODE
#define DEF_CMSGTASKNODE
#include "../msgcenter/MsgCenter.h"
class CMsgTaskNode : public CTaskNode
{
private:
    int m_sockfd;
    int m_cmd;
public:
    CMsgTaskNode();
    CMsgTaskNode(int sockfd);
    ~CMsgTaskNode();
    void setCmd(ushort cmd);
    int getSocket();
};
#endif
