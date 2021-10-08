#include "../include/EventQueue.h"

Event::Event(projectile* prod, int time){
    this->prod = prod;
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    this->Time = std::chrono::duration_cast<std::chrono::milliseconds>(epoch)+ std::chrono::milliseconds(time) ;
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
    auto now = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch);
    while(!this->qu.empty()&&this->qu.front().Time < value){
        this->qu.front().DoIt();
        this->qu.pop();
    }
}

EventQueue::~EventQueue()
{
    //dtor
}
