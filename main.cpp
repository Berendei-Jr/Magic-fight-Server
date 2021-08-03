#include "board.h"
#include <iostream>
#include <map>

int main()
{
    board B(3);
    char n;
    std::map <char, int> direct = {{'a', 0}, {'w', 1}, {'e', 2}, {'d', 3}, {'x', 4}, {'z', 5}};
    hexagon* current_hex=B.center;
    while(1){
        for(int i=0; i<6;i++){
            std::cout<<current_hex->direction[i]<<std::endl;
        }
        std::cout<<std::endl;
        std::cin>>n;
        current_hex=current_hex->direction[direct[n]];
    }
}
