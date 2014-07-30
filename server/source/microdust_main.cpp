#include "../include/Microdust_def.h"

typedef void(*PF_MODEL_INIT)();
extern void msgCenter_init();
extern void taskQueue_init();
extern void threadPool_init();

PF_MODEL_INIT g_models[] = {
    msgCenter_init,
    taskQueue_init,
    threadPool_init
    };


int main(int argc, char* argv[])
{
    int i = 0;
    for(; i < sizeof(g_models) / sizeof(PF_MODEL_INIT); i++)
    {
        g_models[i]();
    }

    return 0;
}



