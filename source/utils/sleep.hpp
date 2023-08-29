


#ifndef SLEEP_HPP
#define SLEEP_HPP

#include <sched.h>
#include <unistd.h>

void gSleep(double time);

class cTimer
{
    public:
        void start(void);
        void reset(void);
    protected:
    private:

};


#endif // SLEEP_HPP
