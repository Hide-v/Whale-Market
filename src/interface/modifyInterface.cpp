#include "../../include/interface/interface.h"

static void modify_passwd() {
    std::string buffer;
    std::cout << "Please input current password: ";
    std::cin >> buffer;
    User* u = getUser(curUser);
    if (u->passwd.compare(buffer)) fail
    std::cout << "Please input new password: ";
    std::cin >> buffer;
    u->passwd = buffer;
    successMessage();
}

make_modify(contact, U, ser)
make_modify(address, U, ser)

static HANDLER handler[] = {modify_passwd, modify_contact, modify_address};
make_interface(M, ODIFY)