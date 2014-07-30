#include "../taskqueue/TaskNode.h"
#include "../msgcenter/MsgProcessor.h"
class CLogoutMsgProcessor : public CMsgProcessor
{
public:
    void process(CTaskNode *&task);
    static CMsgProcessor* getInstance();
};

