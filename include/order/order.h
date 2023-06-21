#ifndef _ORDER_H_
#define _ORDER_H_

#include "../config.h"
#include <string>

typedef struct {
    std::string id;
    std::string good_id;
    double price;
    std::string date;
    std::string seller_id;
    std::string buyer_id;
}Order;

/**
 * @brief pull all order infomation from external file
 * 
 */
void pullOrders();

/**
 * @brief push all order information into external file
 * 
 */
void pushOrders();

/**
 * @brief add Order o to orderss
 * 
 * @param o order to be added
 * @return int 0 if failed else 1
 */
int addOrder(Order* o);

/**
 * @brief print all orders' information
 * 
 */
void printOrders();

/**
 * @brief print orders with seller id
 * 
 * @param id seller id
 */
void printOrders4Seller(std::string id);

/**
 * @brief print orders with buyer id
 * 
 * @param id buyer id
 */
void printOrders4Buyer(std::string id);

#endif