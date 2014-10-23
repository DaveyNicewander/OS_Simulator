#ifndef PCB_H_INCLUDED
#define PCB_H_INCLUDED


#define APPTYPE 0
#define SYSTYPE 1
#include <string>

class PCB
{
public:

    PCB()
    {

    }

    ~PCB()
    {

    }

    std::string processName;
    int processClass;              //0 for APP 1 for SYSTEM
    int priority;                 //-127 to 128
    int state;                   //0 for running, 1 for ready, 2 for blocked
    bool suspended;             //true for suspended, false for not
    int memory;
};














#endif // PCB_H_INCLUDED
