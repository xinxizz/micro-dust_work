#ifndef DEF_CMSGCENTER
#define DEF_CMSGCENTER
#include "../taskqueue/TaskNode.h"
#include "MsgProcessor.h"
#include <map>
#include "../common/Microdust_types.h"

class CMsgCenter{
private:
    std::map<ushort, CMsgProcessor*> m_processors;
    static CMsgCenter *m_msgCenter;

private:
    CMsgCenter();
    bool hasExisted(unsigned short cmd);
    CMsgProcessor * getProcessorsByCmd(ushort cmd);
    
public:
    ~CMsgCenter();
    int unregister(unsigned short cmd);
    int doregister(unsigned short cmd, CMsgProcessor *processor);
    int dispatch(unsigned short cmd, CTaskNode *&processor);
    static CMsgCenter* getInstance();
    static void uninit(std::map<unsigned short, CMsgProcessor*>::iterator it);
};
#endif
