#ifndef DEF_CRSLTASKCONSUMMER
#define DEF_CRSLTASKCONSUMMER
#include "../taskqueue/TaskNode.h"
#include "TaskConsummer.h"
class CRslTaskConsummer : public CTaskConsummer
{
public:
    int consume(CTaskNode *&task);
};

#endif