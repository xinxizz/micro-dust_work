#include "../../include/Microdust_def.h"
#include "TaskNode.h"

CTaskNode::CTaskNode()
{
    m_data = MICRODUST_NULL;
    m_size = 0;
}

CTaskNode::~CTaskNode()
{
}

char *CTaskNode::getData()
{
    return m_data; 
}

void CTaskNode::setData(char *data, size_t size)
{
    this->m_data = data;
    this->m_size = size;
}

CTaskNode::size_t CTaskNode:: getSize()
{
    return m_size;
}

int CTaskNode::toDO()
{
    return MICRODUST_SUCCESS;
}
