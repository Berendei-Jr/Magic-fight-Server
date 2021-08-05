#include <iostream>
#include <map>
#include "object.h"
#include "board.h"
#include "klibriry.h"
int main()
{
    const int radius = 3;
    board B(radius);
    char d;
    std::map <char, int> direct = {{'a', 0}, {'w', 1}, {'e', 2}, {'d', 3}, {'x', 4}, {'z', 5}, {'s', 6}};
    std::map <char, int> :: iterator it;
    hero H(B.center);
    while(1){
        ks::clear();
        B.print();
        std::cout<<std::endl;
        std::cin>>d;
        it = direct.find(d);
        if (it != direct.end()){
            H.move(it->second);
        }

    }
}
