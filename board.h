#ifndef BOARD_H
#define BOARD_H
include <list>
class hexagon
{
    public:
        *hexagon left;
        *hexagon right;
        *hexagon top_left;
        *hexagon top_right;
        *hexagon bot_left;
        *hexagon bot_right;

        int lock_status;
        list <
        list <object>  hex_objects;
}
class board
{
    public:
        board(int radius);
        int radius;
        *hexagon center;
        hexagon GetHexagon(int x, int y, int z);
}
#endif // BOARD_H
