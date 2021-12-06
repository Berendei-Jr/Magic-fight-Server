#ifndef PROJECTILES_H
#define PROJECTILES_H
#include "object.h"

class fireball: public projectile
{
public:
    fireball(hexagon* position, int Creator, int direction);
private:
    int damage=100;
    int SpeedTime=500;
    int direction;
    void TickAction();
    void destroy();
};

#endif // PROJECTILES_H
