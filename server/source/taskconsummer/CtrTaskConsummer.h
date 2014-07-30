#include "../taskqueue/TaskNode.h"
#include "../../include/Microdust_def.h"
#include "TaskConsummer.h"
class CCtrTaskConsummer : public CTaskConsummer
{
private:
    bool m_stop;
public:
    int consume(CTaskNode *&task);
    void stop(bool stop); 
};
