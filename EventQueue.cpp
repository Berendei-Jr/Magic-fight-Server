#include "EventQueue.h"
void Event::DoIt(){
    this->func();
}
EventQueue::EventQueue()
{
    //ctor
}

void EventQueue::push(Event event){
    this->qu.push(event);
}

void EventQueue::tick(){
    while(this->qu.front().Time<clock()){
        this->qu.front().DoIt();
        this->qu.pop();
    }
}

EventQueue::~EventQueue()
{
    //dtor
}
