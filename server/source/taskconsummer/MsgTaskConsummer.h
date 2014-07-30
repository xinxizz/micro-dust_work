#include "TaskConsummer.h"
#include "../msgcenter/MsgCenter.h"

#define TASK_REQUEST_HEAD_LEN 4

class CMsgTaskConsummer : public CTaskConsummer
{
private:
    CMsgCenter *m_msgCenter;
public:
    int consume(CTaskNode *&task);

};
