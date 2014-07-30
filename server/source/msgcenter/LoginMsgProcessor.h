#include "MsgProcessor.h"
#include "../taskqueue/TaskNode.h"
class CLoginMsgProcessor : public CMsgProcessor
{
public:
    void process(CTaskNode *&task);
    static CMsgProcessor* getInstance();
};

