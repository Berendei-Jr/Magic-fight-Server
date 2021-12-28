#ifndef KLIBRIRY_H_INCLUDED
#define KLIBRIRY_H_INCLUDED
#include <iostream>

namespace ks {
    void clear() {
        std::cout << "\x1B[2J\x1B[H";
    }
    void stop(){
        std::cout<<"Press any key to continue...";
        std::cin.ignore();
        std::cin.get();
    }
}


#endif // KLIBRIRY_H_INCLUDED
