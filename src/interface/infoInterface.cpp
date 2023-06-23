#include "../../include/interface/interface.h"

static void info() {
    userInfo(curUser);
    successMessage();
}

static void topUp() {
    std::string buffer;
    std::cout << "Please input the amount of money: ";
    std::cin >> buffer;
    check_double
    User* u = getUser(curUser);
    u->balance += m;
    successMessage();
}

static HANDLER handler[] = {info, MODIFY_Interface, topUp};
make_interface(I, NFO)