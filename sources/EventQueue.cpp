#include "../include/EventQueue.h"

Event::Event(Action_class* act, int time){
    this->act = act;
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    this->Time = std::chrono::duration_cast<std::chrono::milliseconds>(epoch)+ std::chrono::milliseconds(time) ;
}

bool operator< (const Event &ev1, const Event &ev2){
    return ev1.Time>ev2.Time;
}

void Event::DoIt(){
    this->act->TickAction();
}
EventQueue::EventQueue()
{
    //ctor
}

void EventQueue::push(Event event){
    this->qu.push(event);
}

void EventQueue::tick(){
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
    while(!this->qu.empty()&&this->qu.top().Time < value){
        Event ev= this->qu.top();
        ev.DoIt();
        this->qu.pop();
    }
}

EventQueue::~EventQueue()
{
    //dtor
}
