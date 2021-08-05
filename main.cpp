#include <iostream>
#include <map>
#include "object.h"
#include "board.h"
int main()
{
    const int radius = 3;
    board B(radius);
    char n;
    std::map <char, int> direct = {{0, 6}, {'a', 0}, {'w', 1}, {'e', 2}, {'d', 3}, {'x', 4}, {'z', 5}};
    hero H(B.center);
    while(1){
        B.print();
        std::cout<<std::endl;
        std::cin>>n;
        H.move(direct[n]);
    }
}
