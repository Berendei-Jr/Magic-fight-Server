include <list>
class hexagon {
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
class board {
    board(int radius);
    int radius;
    *hexagon center;
    hexagon GetHexagon(int x, int y, int z);

}
