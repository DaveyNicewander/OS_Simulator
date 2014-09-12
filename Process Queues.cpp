#include "PCB.h"
#include "Command.h"







struct QueueNode
{
    QueueNode *next;
    QueueNode *prev;
    PCB *pcb;
};

struct Queue
{
    int nodeCount;
    QueueNode *head;
    QueueNode *tail;
};

PCB * FindPCB(std::string processName);
PCB * AllocatePCB();
void FreePCB(PCB *pcb);
PCB * SetupPCB(std::string processName, int priority, int processClass);
void InsertPCB(Queue Target, PCB *inserted);
void RemovePCB(PCB *removed);


Queue *Ready;
Queue *Blocked;




//_________________________QUEUE FUNCTIONS HERE___________________________

PCB * AllocatePCB()
{
    PCB *newPCB = new PCB();
    return newPCB;
}

void FreePCB(PCB *pcb)
{
    delete pcb;
    return;
}

PCB * SetupPCB(std::string processName, int priority, int processClass)
{
    if (priority > 128 || priority < -127)
    {
        std::cout << "Invalid Priority Setting!" << std::endl;
        return NULL;
    }
    if (processClass < 0 || processClass > 1)
    {
        std::cout << "Invalid Process Class!" << std::endl;
        return NULL;
    }
    if (FindPCB(processName) != NULL)
    {
        std::cout << "A process with that name already exists!" << std::endl;
        return NULL;
    }

    PCB *pcb = AllocatePCB();
    pcb->processName = processName;
    pcb->priority = priority;
    pcb->processClass = processClass;
    pcb->state = 0;
    pcb->suspended = false;

    return pcb;
}

PCB * FindPCB(std::string processName)
{
    QueueNode *traversePtr = Ready->head;
    if(Ready->head->pcb->processName == processName)      //check Ready Queue's head
    {
        return Ready->head->pcb;
    }
    else
    {
        traversePtr = Ready->head->next;
        while (traversePtr->pcb != NULL && traversePtr->next != NULL)      //while not at the end
        {
            if(traversePtr->pcb->processName == processName)
            {
                return traversePtr->pcb;                                  //found same name
            }
            traversePtr = traversePtr->next;                              //move forward
        }
    }

    if(Blocked->head->pcb->processName == processName)      //check Blocked Queue's head
    {
        return Blocked->head->pcb;
    }
    else
    {
        traversePtr = Blocked->head->next;
        while (traversePtr->pcb != NULL && traversePtr->next != NULL)      //while not at the end
        {
            if(traversePtr->pcb->processName == processName)
            {
                return traversePtr->pcb;                                  //found same name
            }
            traversePtr = traversePtr->next;                              //move forward
        }
    }

    return NULL;                                         //if nothing is found return NULL
}

void InsertPCB(Queue *Target, PCB *inserted)
{
    QueueNode *myNodePtr = NULL;
    QueueNode *traversePtr = NULL;

    myNodePtr = new QueueNode;

    myNodePtr->pcb = inserted;
    myNodePtr->next = NULL;
    myNodePtr->prev = NULL;

    if(Target->head->next == NULL)
    {
        Target->head->next = myNodePtr;
        myNodePtr->prev = Target->head;
    }
    else
    {
        traversePtr = Target->head->next;
        while (traversePtr->pcb != NULL && traversePtr->next != NULL)
        {
            traversePtr = traversePtr->next;
        }
        if (traversePtr->next == NULL)
        {
            traversePtr->next = myNodePtr;
            myNodePtr->prev = traversePtr;
        }
    }
}

void RemovePCB(PCB *removed)
{
    removed = FindPCB(removed->processName);

}











