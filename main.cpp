#include <iostream>
#include <map>
#include "object.h"
#include "board.h"
int main()
{
    const int radius = 3;
    board B(radius);
    char n;
    std::map <char, int> direct = {{'a', 0}, {'w', 1}, {'e', 2}, {'d', 3}, {'x', 4}, {'z', 5}};
    hexagon* current_hex=B.center;
    while(1){
        B.print();
        std::cout<<std::endl;
        std::cin>>n;
        current_hex=current_hex->direction[direct[n]];
    }
}
