#include "board.h"
hexagon::hexagon(){
    this->lock_status=0;
}
board::board(int radius){
    hexagon* new_hex=new hexagon();
    this->center= new_hex;
    hexagon* current_hex=this->center;
    for(int i=2; i<=radius; i++){
        current_hex=current_hex->direction[0];
        new_hex=new hexagon();
        current_hex->direction[0]= new_hex;
        new_hex->direction[4]=current_hex;
        for(int j = 0; j<6; j++)
        for(int k=0; k<=i; k++){
            new_hex=new hexagon();
            current_hex->direction[(1+j)%6]=current_hex->direction[(0+j)%6]->direction[(2+j)%6]=new_hex;
            new_hex->direction[(5+j)%6]=current_hex->direction[(0+j)%6];
            new_hex->direction[(4+j)%6]=current_hex;
            current_hex=current_hex->direction[(3+j)%6];
        }
    }
}
