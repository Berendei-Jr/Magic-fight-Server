#include "NetModule.hpp"

#include <iostream>
#include <thread>

int main() {
    unsigned int n = std::thread::hardware_concurrency();
    std::cout << n << " concurrent threads are supported.\n";
    NetModule nm(6969);
    std::this_thread::sleep_for(std::chrono::milliseconds(50000));
    std::cout << "End!\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100000));
}
