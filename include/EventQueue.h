#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H
#include <queue>
#include <chrono>
#include "object.h"

class Event
{
public:
    Event(Action_class* act, int time);
    friend bool operator< (const Event &ev1, const Event &ev2);
private:
    std::chrono::milliseconds Time;
    Action_class* act;

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
        std::priority_queue <Event> qu;
};

#endif // EVENTQUEUE_H
