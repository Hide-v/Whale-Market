#include "../../include/interface/interface.h"
#include <iostream>

void inv() { 
    invalidMessage(); 
    failureMessage();
}

make_login(U, SER, checkPass(username, passwd, &curUser))
make_login(A, DMIN, username.compare(ADMIN_NAME) == 0 && passwd.compare(ADMIN_PASS) == 0)

static void USER_SignUp() {
    User* u = new User;
    std::cout << "Please input your username: ";
    std::cin >> u->name;
    std::cout << "Please input your password: ";
    std::cin >> u->passwd;
    std::cout << "Please input your phone number: ";
    std::cin >> u->contact;
    std::cout << "Please input your address: ";
    std::cin >> u->address;
    u->balance = 0;
    if (addUser(u)) successMessage();
    else failureMessage();
    delete u;
}

static HANDLER handler[] = {USER_Login, USER_SignUp, ADMIN_Login};

make_interface(M, AIN)
