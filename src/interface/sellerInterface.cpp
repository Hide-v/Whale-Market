#include "../../include/interface/interface.h"

static void sell() {
    User* seller = getUser(curUser);
    Good* g = new Good;
    std::cout << "Please input the information of your product ...\n";
    std::cout << "Name: ";
    std::cin >> g->name;
    std::cout << "Price: ";
    std::string buffer;
    std::cin >> buffer;
    check_double
    g->price = m;
    std::cout << "Description: ";
    std::cin >> g->description;
    g->seller_id = seller->id;
    if (addGood(g)) successMessage();
    else failureMessage();
    delete g;
}

static void modify() {
    std::cout << "Please input the good ID to modify: ";
    std::string buffer;
    std::cin >> buffer;
    curGood = searchGoodID(buffer);
    if (curGood == -1) fail
    User* u = getUser(curUser);
    Good* g = getGood(curGood);
    if (u->id.compare(g->seller_id) == 0 && g->state == SELLING) 
        GOOD_Interface();
    else failureMessage();
}

make_my(Goods, S, eller)
make_my(Orders, S, eller)

make_ban(G, ood, "Good", getUser(curUser)->id);

static HANDLER handler[] = {sell, myGoods, modify, banGood, myOrders};
make_interface(S, ELLER)