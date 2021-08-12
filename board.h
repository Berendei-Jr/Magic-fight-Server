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
        int* GetCoordinate();
    private:
        int* coordinate;

        void link(hexagon* link_hex, int direction);
        void ChangeCoordinate(int x, int y);
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
        void ChangrHash();
        int GetHash();
    private:
        int hash;
};
#endif // BOARD_H
