#ifndef DEF_CRslTASKNODE
#define DEF_CRslTASKNODE
class CRslTaskNode : public CTaskNode
{
private:
    int m_sockfd;
public:
    CRslTaskNode(int sock);
    ~CRslTaskNode();
public:
    int getSockfd();
};
#endif
