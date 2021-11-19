#include <iostream>
#include <map>
#include "../include/object.h"
#include "../include/board.h"
#include "../include/klibriry.h"
#include <SFML/Graphics.hpp>
#include <Server.hpp>

int main()
{
   // net::Server Server(60000);
  
  
    const int radius = 5;
    board B(radius);
    char d, act_key;
    int* a;
    bool b=0;
    int saved_hash = -1;
    std::map <char, int> direct = {{'a', 0}, {'w', 1}, {'e', 2}, {'d', 3}, {'x', 4}, {'z', 5}, {'s', 6}};
    std::map <char, int> action_map = {{'k', 0}, {'o', 1}, {'l', 2}, {'p', 3}};
    std::map <char, int> :: iterator it1, it2;
    ActionsList hero_actions[4];
    hero_actions[0]=Step;
    hero_actions[1]=Fireball;
    hero_actions[2]=Leap;
    hero_actions[3]=Wizard;
    sf::Texture hero_texture;
    if (!hero_texture.loadFromFile("/home/supsun/Documents/Magic_fight/img/hero.png"))
        return EXIT_FAILURE;
    hero H(B.center, hero_texture, hero_actions, 1);
    //hero H2(B.center, hero_texture, hero_actions, 2);
    sf::RenderWindow window(sf::VideoMode(486, 434), "Magic Fight");
    sf::Texture board_textr;
    if (!board_textr.loadFromFile("/home/supsun/Documents/Magic_fight/img/board.png"))
        return EXIT_FAILURE;
    sf::Sprite board(board_textr);

    return 0;
}
