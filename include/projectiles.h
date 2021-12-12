#ifndef PROJECTILES_H
#define PROJECTILES_H
#include "object.h"

class fireball: public projectile
{
public:
    fireball(hexagon* position, int Creator, int direction);
private:
    int damage;
    int SpeedTime;
    int direction;
    void TickAction();
    void destroy();
};

#endif // PROJECTILES_H
