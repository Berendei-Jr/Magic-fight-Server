#include "action_classes.h"
#include <iostream> //TODO delete
mana_creator::mana_creator(EventQueue* queue, int mana_count, hero* owner, int SpeedTime):Action_class(SpeedTime){
    this->mana_count=mana_count;
    this->owner=owner;
    this->queue=queue;
    Event* ev=new Event(this, this->SpeedTime);
    this->queue->push(*ev);
}

void mana_creator::TickAction(){
    this->owner->add_mana(this->mana_count);
    Event* ev=new Event(this, this->SpeedTime);
    //std::cout<<this->owner->number<< " " <<this->owner->cur_mana << " " << this->owner->health<<std::endl;
    this->queue->push(*ev);
}
