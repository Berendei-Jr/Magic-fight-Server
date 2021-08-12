#include <iostream>
#include <map>
#include "object.h"
#include "board.h"
#include "klibriry.h"
#include <SFML/Graphics.hpp>
int main()
{
    const int radius = 5;
    board B(radius);
    char d;
    std::map <char, int> direct = {{'a', 0}, {'w', 1}, {'e', 2}, {'d', 3}, {'x', 4}, {'z', 5}, {'s', 6}};
    std::map <char, int> :: iterator it;
    hero H(B.center, Step, 1);
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(452, 411), "SFML window");
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("img/board.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                d = event.key.code + 97;
                ks::clear();
                B.print();
                //std::cout<<std::endl;
                //std::cin>>d;
                std::cout << d;
                it = direct.find(d);
                if (it != direct.end()){
                    H.skill->DoIt(it->second);
                }
            }
        }
        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
