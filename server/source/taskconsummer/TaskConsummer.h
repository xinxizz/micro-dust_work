#ifndef DEF_CTASKCONSUMMER
#define DEF_CTASKCONSUMMER
#include "../taskqueue/TaskNode.h"
class CTaskConsummer
{
private:
public:
    virtual int consume(CTaskNode *&task);        
};
#endif
