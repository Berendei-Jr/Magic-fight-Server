#include <iostream>
#include <map>
#include "object.h"
#include "board.h"
#include "klibriry.h"
#include <SFML/Graphics.hpp>
void CoordinatesAdapter (int* a){
    const int zx=27;
    const int zy=47;
    a[0]=(a[0]+a[0]-a[1])*zx+232;
    a[1]=207-a[1]*zy;
}
int main()
{
    const int radius = 5;
    board B(radius);
    char d, act_key;
    int* a;
    bool b;
    int saved_hash = -1;
    std::map <char, int> direct = {{'a', 0}, {'w', 1}, {'e', 2}, {'d', 3}, {'x', 4}, {'z', 5}, {'s', 6}};
    std::map <char, int> action_map = {{'k', 0}, {'o', 1}, {'l', 2}, {'p', 3}};
    std::map <char, int> :: iterator it1, it2;
    ActionsList hero_actions[4];
    hero_actions[0]=Step;
    hero_actions[1]=Fireball;
    hero_actions[2]=Step;
    hero_actions[3]=Step;
    sf::Texture hero_texture;
    if (!hero_texture.loadFromFile("img/hero.png"))
        return EXIT_FAILURE;
    hero H(B.center, hero_texture, hero_actions, 1);
    //hero H2(B.center, hero_texture, hero_actions, 2);
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
            if (event.type == sf::Event::KeyPressed)
            {
                d = event.key.code + 97;
                if (b){
                    it1 = direct.find(d);
                    if (it1 != direct.end()){
                        H.skills[it2->second]->DoIt(it1->second);
                    }
                    b=false;
                } else {
                    act_key=d;
                    it2 = action_map.find(act_key);
                    b=it2 !=action_map.end();
                }

            }
        }
        B.Tick();
        if (saved_hash!=B.GetHash())
        {
            saved_hash=B.GetHash();
            window.clear();
            window.draw(board);
            for(auto it=B.all_objects.begin(); it!=B.all_objects.end(); it++){
                object* temporary = *it;
                a = temporary->position->GetCoordinate();
                std::cout << a[0] << " " << a[1]<< std::endl;
                CoordinatesAdapter(a);
                temporary->sprite.setPosition(a[0], a[1]);
                window.draw(temporary->sprite);
                delete[] a;
            }
            //window.draw(H.sprite);
            window.display();
        }

    }
    return EXIT_SUCCESS;
}
