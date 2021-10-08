#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H
#include <queue>
#include <chrono>
#include "object.h"

class Event
{
public:
    Event(projectile* prod, int time);
private:
    std::chrono::milliseconds Time;
    projectile* prod;

    void DoIt();

    friend class EventQueue;
};

class EventQueue
{
    public:
        EventQueue();
        ~EventQueue();

        void push(Event event);
        //void DelEvent(int id);
        void tick();


    protected:

    private:
        std::queue <Event> qu;
};

#endif // EVENTQUEUE_H
