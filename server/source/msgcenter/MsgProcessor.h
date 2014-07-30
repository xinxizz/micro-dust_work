#ifndef DEF_CMSGPROCESSOR
#define DEF_CMSGPROCESSOR
#include "../taskqueue/TaskNode.h"
class CMsgProcessor
{
public:
    CMsgProcessor();
    virtual void process(CTaskNode *&);
    virtual ~CMsgProcessor();

    template <class T>
    static CMsgProcessor* getInstance()
    {
        return new T();
    }
};
#endif

