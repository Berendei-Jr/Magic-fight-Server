#include "board.h"
#include <iostream>
#include <map>

/*void print(){
    for(int i=0; i<radius;i++){
        for(int j=0; j<radius-1-i; j++){
            std::cout<<" ";
        }
        for(int j=0; j<radius+i-1; j++){
            std::cout<<"+ ";
        }
        std::cout<<"+";
        for(int j=0; j<radius-1-i; j++){
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    for(int i=radius-2; i>=0; i--){
        for(int j=0; j<radius-1-i; j++){
            std::cout<<" ";
        }
        for(int j=0; j<radius+i-1; j++){
            std::cout<<"+ ";
        }
        std::cout<<"+";
        for(int j=0; j<radius-1-i; j++){
            std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}*/

int main()
{
    const int radius = 3;
    board B(radius);
    char n;
    std::map <char, int> direct = {{'a', 0}, {'w', 1}, {'e', 2}, {'d', 3}, {'x', 4}, {'z', 5}};
    hexagon* current_hex=B.center;
    while(1){
        print();
        std::cout<<std::endl;
        std::cin>>n;
        current_hex=current_hex->direction[direct[n]];
    }
}
