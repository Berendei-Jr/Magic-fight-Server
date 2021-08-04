#ifndef BOARD_H
#define BOARD_H
#include <list>
#include "object.h"
class hexagon
{
    public:
        hexagon();
        hexagon** direction= new hexagon*[6];
        int lock_status;
        std::list <int>  hex_objects;//std::list <object*>  hex_objects;

        void link(hexagon* link_hex, int direction);
        hexagon* NextHex(int direction);

};
class board
{
    public:
        board(int radius);
        int radius;
        hexagon* center;
        hexagon GetHexagon(int x, int y);

        void print();
        hexagon* HexByCoordinates(int x, int y){

        }
};
#endif // BOARD_H
