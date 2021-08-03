#ifndef BOARD_H
#define BOARD_H
#include <list>
#include "object.h"
class hexagon
{
    public:
        hexagon();
        hexagon** direction= new hexagon*[6];
        void link(hexagon* link_hex, int direction);

        int lock_status;
        //std::list <object*>  hex_objects;
};
class board
{
    public:
        board(int radius);
        int radius;
        hexagon* center;
        hexagon GetHexagon(int x, int y);
};
#endif // BOARD_H
