#ifndef ACTION_CLASSES_H
#define ACTION_CLASSES_H
#include "object.h"
#include "EventQueue.h"

class mana_creator: Action_class
{
private:
    hero* owner;
    int mana_count;
    EventQueue* queue;
public:
    mana_creator(EventQueue* queue, int mana_count, hero* owner, int SpeedTime);
    void TickAction();
};

#endif // ACTION_CLASSES_H
