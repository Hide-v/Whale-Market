#include <iostream>
#include "include/interface/interface.h"
#include "include/tools/hint.h"

int main()
{
    pullUsers();
    pullGoods();
    pullOrders();

    welcomeMessage();
    MAIN_Interface();
    exitingMessage();
    
    pushUsers();
    pushGoods();
    pushOrders();
    return 0;
}