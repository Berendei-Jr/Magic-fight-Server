#ifndef BOARD_H
#define BOARD_H
#include "object.h"
#include <list>
class board;

class hexagon
{
    public:
        hexagon(board* owner);
        board* owner;
        hexagon** direction;
        int lock_status;
        std::list <object*>  hex_objects;

        void AddObject(object* new_object);
        void DelObject(object* del_object);
        hexagon* NextHex(int direction);
    private:
        void link(hexagon* link_hex, int direction);
    friend class board;


};
class board
{
    public:
        board(int radius);
        int radius;
        hexagon* center;
        std::list <object*>  all_objects;

        void print();
        hexagon* HexByCoordinates(int x, int y);
};
#endif // BOARD_H
