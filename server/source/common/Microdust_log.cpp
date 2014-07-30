#include "Microdust_log.h"

int CMicrodustLog::level = 4;

void CMicrodustLog::info()
{
    if (1 >= level)
    {
        
    }
}

void CMicrodustLog::dbg()
{
    if (2 >= level)
    {
        
    }
}

void CMicrodustLog::warn()
{
    if (3 >= level)
    {
        
    }
}

void CMicrodustLog::err()
{
    if (4 >= level)
    {
    }
}

void CMicrodustLog::setDbg(int level)
{
    CMicrodustLog::level = level;    
}