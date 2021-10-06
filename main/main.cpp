#include "Server.hpp"

int main(){
    Server S;
    S.init(7777);
    S.run();
    S.end();
    return 0;
};

