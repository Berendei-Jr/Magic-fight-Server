#include <iostream>
#include <map>
#include "../include/object.h"
#include "../include/board.h"
#include "../include/klibriry.h"
#include <SFML/Graphics.hpp>
#include <Server.hpp>
#include <sstream>

void CoordinatesAdapter (int* a)
{
    const int zx=27;
    const int zy=47;
    a[0]=(a[0]+a[0]-a[1])*zx+232;
    a[1]=207-a[1]*zy;
}

int main(int argc, char* argv[])
{
    bool encryption = true;
    if (argc == 2)
    {
        encryption = std::stoi(argv[1]);
    }

    net::Server Server(6969, encryption);
  
    const int radius = 5;
    board B(radius);
    char d, act_key;
    int* a;
    bool b = 0;
    int n_act, direction;
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
    if (!hero_texture.loadFromFile("img/hero.png"))
        return EXIT_FAILURE;
    hero* heros[2];

    hero H0(B.center, hero_texture, hero_actions, 1);
    hero H1(B.center, hero_texture, hero_actions, 2);
    heros[0]=&H0;
    heros[1]=&H1;
    sf::RenderWindow window(sf::VideoMode(486, 434), "Magic Fight");
    sf::Texture board_textr;
    if (!board_textr.loadFromFile("img/board.png"))
        return EXIT_FAILURE;
    sf::Sprite board(board_textr);
    sf::Time duration = sf::milliseconds(16);
    while (window.isOpen())
    {
        sf::sleep(duration);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

        }
        if (Server.Ready())
        {
            Msg tmp = Server.Get();
            std::cout << tmp << std::endl;
            std::stringstream remote;
            remote << tmp._data;
            remote >> n_act;
            remote >> direction;
            heros[tmp._id]->make_action(n_act, direction);

        }
        B.Tick();
        if (saved_hash != B.GetHash())
        {
            saved_hash=B.GetHash();
            window.clear();
            window.draw(board);
            for (auto it=B.all_objects.begin(); it!=B.all_objects.end(); it++){
                object* temporary = *it;
                a = temporary->position->GetCoordinate();
                std::cout << a[0] << " " << a[1]<< std::endl;
                CoordinatesAdapter(a);
                temporary->sprite.setPosition(a[0], a[1]);
                window.draw(temporary->sprite);
                delete[] a;
            }
            window.display();
        }
    }
    return EXIT_SUCCESS;
}
