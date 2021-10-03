#include "board.h"
#include <iostream>
#include <list>
hexagon::hexagon(board* owner)
{
    this->coordinate=new int[2];
    this->lock_status=0;
    this->hex_objects={};
    this->direction= new hexagon*[7];
    this->direction[6]=this;
    this->owner=owner;
}

int* hexagon::GetCoordinate(){
    int* a =new int[2]{this->coordinate[0], this->coordinate[1]};
    return a;
}

void hexagon::ChangeCoordinate(int x, int y)
{
    this->coordinate[0]=x;
    this->coordinate[1]=y;
}

void hexagon::AddObject(object* new_object)
{
    this->hex_objects.push_back(new_object);
    this->owner->all_objects.push_back(new_object);
}

void hexagon::DelObject(object* del_object)
{
    this->hex_objects.remove(del_object);
    this->owner->all_objects.remove(del_object);
}

void hexagon::link(hexagon* link_hex, int direction){
    this->direction[direction]=link_hex;
    link_hex->direction[(direction+3)%6]=this;
}
hexagon* hexagon::NextHex(int direction)
{
    return this->direction[direction];
}
board::board(int radius)
{
    this->hash=0;
    this->radius=radius;
    this->event_queue=EventQueue();
    hexagon* new_hex = new hexagon(this);
    this->center= new_hex;
    hexagon* current_hex=this->center;
    for(int i = 0; i<6; i++){
        new_hex = new hexagon(this);
        this->center->link(new_hex, (0+i)%6);
    }
    for(int i=0; i<6; i++){
        current_hex->direction[(0+i)%6]->link(current_hex->direction[(1+i)%6], (2+i)%6);
    }
    for(int i=2; i<radius; i++){
        current_hex=current_hex->direction[0];
        for(int j = 0; j<6; j++){
            new_hex=new hexagon(this);
            current_hex->link(new_hex, (0+j)%6);
            for(int k=0; k<i-1; k++){
                current_hex=current_hex->direction[(2+j)%6];
                new_hex=new hexagon(this);
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
    for(int i=0; i<this->radius; i++)
    {
        current_hex=this->HexByCoordinates(-i, this->radius-i-1);
        for(int j=0; j<this->radius+i; j++)
        {
            current_hex->ChangeCoordinate(-i+j, this->radius-i-1);
            current_hex= current_hex->NextHex(3);
        }
    }
    for(int i=1; i<this->radius; i++)
    {
        current_hex=this->HexByCoordinates(-this->radius+1, -i);
        for(int j=0; j<radius*2-1-i; j++)
        {
            current_hex->ChangeCoordinate(-this->radius+1+j, -i);
            current_hex= current_hex->NextHex(3);
        }
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

int board::GetHash()
{
    return this->hash;
}

void board::ChangrHash()
{
    this->hash++;
}
