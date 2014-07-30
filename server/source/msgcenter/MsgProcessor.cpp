#include "MsgProcessor.h"
#include "../common/Microdust_log.h"

CMsgProcessor::CMsgProcessor()
{
}

void CMsgProcessor::process(CTaskNode *&task)
{
    return;
}

CMsgProcessor::~CMsgProcessor()
{
    CMicrodustLog::dbg();
}