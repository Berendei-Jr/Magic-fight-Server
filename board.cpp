#include "board.h"
hexagon::hexagon(){
    this->lock_status=0;
}
void hexagon::link(hexagon* link_hex, int direction){
    this->direction[direction]=link_hex;
    link_hex->direction[(direction+3)%6]=this;
}
board::board(int radius){
    hexagon* new_hex=new hexagon();
    this->center= new_hex;
    hexagon* current_hex=this->center;
    for(int i = 0; i<6; i++){
        new_hex=new hexagon();
        this->center->link(new_hex, (0+i)%6);
    }
    for(int i=0; i<6; i++){
        current_hex->direction[(0+i)%6]->link(current_hex->direction[(1+i)%6], (2+i)%6);
    }
    for(int i=2; i<radius; i++){
        current_hex=current_hex->direction[0];
        for(int j = 0; j<6; j++){
            new_hex=new hexagon();
            current_hex->link(new_hex, (0+j)%6);
            for(int k=0; k<i-1; k++){
                current_hex=current_hex->direction[(2+j)%6];
                new_hex=new hexagon();
                current_hex->link(new_hex, (0+j)%6);
                current_hex->direction[(5+j)%6]->link(new_hex, (1+j)%6);
                current_hex->direction[(5+j)%6]->direction[(0+j)%6]->link(new_hex, (2+j)%6);
            }
        }
        for(int j=0; j<6; j++){
            current_hex->direction[(0+j)%6]->link(current_hex->direction[(5+j)%6], (4+j)%6);
            for(int k=0; k<i-1; k++){
                current_hex=current_hex->direction[(2+j)%6];
            }
        }
    }
}
