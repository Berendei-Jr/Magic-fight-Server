#include "board.h"
#include <iostream>
#include <list>
hexagon::hexagon(){
    this->lock_status=0;
    this->hex_objects={};
    //this->direction[7]=this;
}

void hexagon::link(hexagon* link_hex, int direction){
    this->direction[direction]=link_hex;
    link_hex->direction[(direction+3)%6]=this;
}
hexagon* hexagon::NextHex(int direction)
{
    return this->direction[direction];
}
board::board(int radius){
    this->radius=radius;
    hexagon* new_hex = new hexagon();
    this->center= new_hex;
    hexagon* current_hex=this->center;
    for(int i = 0; i<6; i++){
        new_hex = new hexagon();
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

void board::print()
{
    int k;
    hexagon* current_hex;
    for(int i=0; i<this->radius; i++)
    {
        char* A = new char[this->radius*4-3];
        current_hex=this->HexByCoordinates(-i, this->radius-i-1);
        k=this->radius-1-i;
        for(int j=0; j<radius+i; j++)
        {
            if (current_hex->hex_objects.size()==0)
            {
                A[k]='+';
            } else
            {
                A[k]='0';
            }
            k+=2;
            current_hex= current_hex->NextHex(3);
        }
        for(int j=0; j<this->radius*4-3; j++){
            if(A[j]==0){
                std::cout<<' ';
            }
            std::cout<<A[j];
        }
        std::cout<<std::endl;
    }
    for(int i=1; i<this->radius; i++)
    {
        char* A = new char[this->radius*4-3];
        current_hex=this->HexByCoordinates(-this->radius+1, -i);
        k=i;
        for(int j=0; j<radius*2-1-i; j++)
        {
            if (current_hex->hex_objects.size()==0)
            {
                A[k]='+';
            } else
            {
                A[k]=current_hex->hex_objects.front()->icon;
            }
            k+=2;
            current_hex= current_hex->NextHex(3);
        }
        for(int j=0; j<this->radius*4-3; j++){
            if(A[j]==0){
                std::cout<<' ';
            }
            std::cout<<A[j];
        }
        std::cout<<std::endl;
    }
}
hexagon* board::HexByCoordinates(int x, int y)
{
    hexagon* current_hex=this->center;
    for(int i=0; i<x; i++)
    {
        current_hex=current_hex->NextHex(3);
    }
    for(int i=0; i<-x; i++)
    {
        current_hex=current_hex->NextHex(0);
    }
    for(int i=0; i<y; i++)
    {
        current_hex=current_hex->NextHex(1);
    }
    for(int i=0; i<-y; i++)
    {
        current_hex=current_hex->NextHex(4);
    }
    return current_hex;
}
