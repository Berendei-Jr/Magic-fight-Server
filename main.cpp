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
    char d;
    int* a;
    int saved_hash = -1;
    std::map <char, int> direct = {{'a', 0}, {'w', 1}, {'e', 2}, {'d', 3}, {'x', 4}, {'z', 5}, {'s', 6}};
    std::map <char, int> :: iterator it;
    sf::Texture hero_texture;
    if (!hero_texture.loadFromFile("img/hero.png"))
        return EXIT_FAILURE;
    ActionsList hero_actions[4];
    hero_actions[0]=Step;
    hero H(B.center, hero_texture, hero_actions, 1);
    sf::RenderWindow window(sf::VideoMode(486, 434), "Magic Fight");
    sf::Texture texture;
    if (!texture.loadFromFile("img/board.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

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
                it = direct.find(d);
                if (it != direct.end()){
                    H.skills[0]->DoIt(it->second);
                }
            }
        }
        if (saved_hash!=B.GetHash())
        {
            saved_hash=B.GetHash();
            window.clear();
            a = H.position->GetCoordinate();
            std::cout << a[0] << " " << a[1]<< std::endl;
            CoordinatesAdapter(a);
            H.sprite.setPosition(a[0], a[1]);
            delete[] a;
            window.draw(sprite);
            window.draw(H.sprite);
            window.display();
        }

    }
    return EXIT_SUCCESS;
}
