#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H
#include <queue>

class Event
{
public:
    Event(void (*func)());
private:
    int Time;
    void  (*func)();

    void DoIt();

    friend class EventQueue;
};

class EventQueue
{
    public:
        EventQueue();
        ~EventQueue();

        int AddEvent(Event event);
        //void DelEvent(int id);
        void tick();


    protected:

    private:
        std::queue <Event> queue;
};

#endif // EVENTQUEUE_H
