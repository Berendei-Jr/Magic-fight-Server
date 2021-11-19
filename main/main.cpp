#include <iostream>
#include <map>
#include "../include/object.h"
#include "../include/board.h"
#include "../include/klibriry.h"
#include <SFML/Graphics.hpp>
#include <Server.hpp>

int main()
{
    net::Server Server(60000);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    Msg m = { 100, "hi" };
    Server.Send(m);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    m._id = 100;
    m._data = "Hello Daniel!\n";
    Server.Send(m);


    std::cout << "Ready? " << Server.Ready() << "\n";
    std::cout << "Top: " << Server.Top() << "\n";
    std::cout << "Size: " << Server.NumOfMsgAvailable() << "\n";

    std::this_thread::sleep_for(std::chrono::seconds(60));

    return 0;
}
