#include "MsgCenter.h"
#include "MsgProcessor.h"
#include "../common/Microdust_error.h"
#include "../../include/Microdust_def.h"
#include "../common/Microdust_log.h"
#include <algorithm>
#include <iterator>

CMsgCenter* CMsgCenter::m_msgCenter = MICRODUST_NULL;

CMsgCenter::CMsgCenter()
{
    
}

CMsgCenter::~CMsgCenter()
{
    //for_each(m_processors.begin(), m_processors.end(), &CMsgCenter::uninit);
    m_processors.clear();
}

CMsgCenter* CMsgCenter::getInstance()
{
    if (m_msgCenter == MICRODUST_NULL)
    {
        m_msgCenter = new CMsgCenter();
    }
    return m_msgCenter;
}

void CMsgCenter::uninit(std::map<unsigned short, CMsgProcessor*>::iterator it)
{
    if (MICRODUST_NULL == it->second)
    {
        return;
    }
    
    delete it->second;
    it->second = MICRODUST_NULL;
}
int CMsgCenter::dispatch(unsigned short cmd, CTaskNode *&task)
{
    CMsgProcessor *tmp = getProcessorsByCmd(cmd);
    if (MICRODUST_NULL == tmp)
    {
        CMicrodustLog::warn();
        return MDJSS_MSG_NO_PROCESSOR_ERR;
    }

    tmp->process(task);
    return MICRODUST_SUCCESS;
}
int CMsgCenter::doregister(unsigned short cmd, CMsgProcessor *processor)
{    
    int ret = MICRODUST_SUCCESS;
    CMicrodustLog::info();
    ASSERTPTR(processor)

    m_processors[cmd] = processor;
 
    return ret;
}

int CMsgCenter::unregister(unsigned short cmd)
{
    int ret = MICRODUST_SUCCESS;
    CMicrodustLog::info();
    if (!hasExisted(cmd))
    {
        return ret;
    }

    delete m_processors[cmd];
    m_processors.erase(m_processors.find(cmd));
    return ret;
}

CMsgProcessor *CMsgCenter::getProcessorsByCmd(unsigned short cmd)
{
    std::map<unsigned short, CMsgProcessor*>::iterator it = m_processors.find(cmd);
    if (it == m_processors.end())
    {
        return MICRODUST_NULL;
    }

    return m_processors[cmd];
}

bool CMsgCenter::hasExisted(ushort cmd)
{
    CMsgProcessor *tmp = getProcessorsByCmd(cmd);
    if (MICRODUST_NULL == tmp)
    {
        return true;
    }

    return false;
}



