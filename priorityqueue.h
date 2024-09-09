#pragma once

struct Elements
{
    int num;
    int priority;
};

class priorityqueue
{
    public:
        virtual void enqueue(int value, int priority) = 0;
        virtual int dequeueHighestPriority() = 0;
        virtual int peekHighestPriority() = 0;
        virtual void updatePriority(int value, int new_priority) = 0;
        virtual int getSize() = 0;
        virtual void clear() = 0;
        virtual double getAveragePriority() = 0;
};
