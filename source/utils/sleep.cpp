


#include "sleep.hpp"

void gSleep(double time)
{
    #ifdef WIN32
        Sleep((DWORD)(time*1000));
    #else
    if(time == 0.0)
    {
        sched_yield(); // sched.h
    }
    else
    {
        usleep((useconds_t)(time*1000000)); // unistd.h
    }
    #endif
}
