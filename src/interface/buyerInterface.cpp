#include "../../include/interface/interface.h"

static void buy() {
    std::string buffer;
    std::cout << "Please input Good id to buy: ";
    std::cin >> buffer;
    int idx = searchGoodID(buffer);
    if (idx == -1) fail

    Good* g = getGood(idx);
    User* u = getUser(curUser); // buyer

    if (g->state != SELLING) fail
    if (g->price > u->balance) fail
    
    u->balance -= g->price;
    g->state = SOLD;
    userTopUp(g->seller_id, g->price);

    // generate an order
    Order* o = new Order;
    o->good_id = g->id;
    o->seller_id = g->seller_id;
    o->buyer_id = u->id;
    o->price = g->price;

    if (addOrder(o)) successMessage();
    else failureMessage();
    delete o;
}

static void info() {
    std::string buffer;
    std::cout << "Please input Good ID for more information: ";
    std::cin >> buffer;
    int idx = searchGoodID(buffer);
    if (idx == -1) fail
    loadingMessage();
    goodInfo(idx);
    successMessage();
}

make_search(Buyer)

make_my(Goods, B, uyer)
make_my(Orders, B, uyer)

static HANDLER handler[] = {myGoods, buy, search, myOrders, info};
make_interface(B, UYER)