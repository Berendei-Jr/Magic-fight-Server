#include "EventQueue.h"
Event::Event(projectile* prod){
    this->prod = prod;
}

void Event::DoIt(){
    this->prod->TickAction();
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
