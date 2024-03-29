#ifndef _INTERFACE_H_
#define _INTERFACE_H_
#include "../../include/tools/hint.h"
#include "../../include/menu/menu.h"
#include "../../include/user/user.h"
#include "../../include/good/good.h"
#include "../../include/order/order.h"
#include <iostream>

extern int curUser;

extern int curGood;

typedef void (*HANDLER)(void);

void inv();

/* An interface gets user input with corresponding menu and handles it. */

/**
 * @brief 
 * | 1.User Login | 2.User Sign Up | 3.Admin Login | 4.Exit |
 */
void MAIN_Interface();

/**
 * @brief 
 * | 1.Goods | 2.Search | 3.Orders | 4.Users | 5.Delete | 6.Ban | 7.Back |
 */
void ADMIN_Interface();

/**
 * @brief 
 * | 1.Buyer | 2.Seller | 3.Information | 4.Back |
 */
void USER_Interface();

/**
 * @brief 
 * | 1.Goods | 2.Buy | 3.Search | 4.Order | 5.Infomation | 6.Back |
 */
void BUYER_Interface();

/**
 * @brief 
 * | 1.Sell | 2.Goods | 3.Modify | 4.Ban | 5.Order | 6.Back |
 */
void SELLER_Interface();

/**
 * @brief 
 * | 1.Information | 2.Modify | 3.Top Up | 4.Back |
 */
void INFO_Interface();

/**
 * @brief 
 * | 1.Password | 2.Contact | 3.Address | 4.Back |
 */
void MODIFY_Interface();

/**
 * @brief 
 * | 1.Name | 2.Price | 3.Description | 4.Back |
 */
void GOOD_Interface();

#define make_interface(T, YPE)\
void T##YPE##_Interface() {\
    successMessage();\
    int op = menu(T##YPE);\
    while (op != optionNum[T##YPE]) {\
        loadingMessage();\
        handler[op - 1]();\
        op = menu(T##YPE);\
    }\
    loadingMessage();\
    successMessage();\
}

#define get_username_passwd\
    std::string username;\
    std::string passwd;\
    std::cout << "Username: ";\
    std::cin >> username;\
    std::cout << "Password: ";\
    std::cin >> passwd;

#define make_login(T, YPE, cond)\
static void T##YPE##_Login() {\
    get_username_passwd\
    if (cond) { T##YPE##_Interface(); return ; }\
    failureMessage();\
}

#define make_all(T, YPE)\
static void all##T##YPE##s() { print##T##YPE##s(); successMessage(); }

#define make_ban(T, YPE, Name, Who)\
static void ban##T##YPE() {\
    std::string id;\
    std::cout << "Please input " << Name <<  " ID to be banned: ";\
    std::cin >> id;\
    if (delete##T##YPE(id, Who)) successMessage();\
    else failureMessage();\
}

#define make_search(WHO)\
static void search() {\
    std::string buffer;\
    std::cout << "Please input Good Name to search: ";\
    std::cin >> buffer;\
    loadingMessage();\
    searchGoodName4##WHO(buffer);\
    successMessage();\
}

#define check_double\
    double m = stod(buffer);\
    while (1) {\
        if (m > 0) break;\
        illegalMessage();\
        std::cout << "Please try again: ";\
        std::cin >> buffer;\
        m = stod(buffer);\
    }

#define make_modify(TYPE, W, HO) \
static void modify_##TYPE() {\
    std::string buffer;\
    std::cout << "Please input new "<< #TYPE << ": ";\
    std::cin >> buffer;\
    W##HO* x = get##W##HO(cur##W##HO);\
    x->TYPE = buffer;\
    successMessage();\
}

#define make_my(TYPE, W, HO) \
static void my##TYPE() {\
    print##TYPE##4##W##HO(getUser(curUser)->id);\
    successMessage();\
}

#define fail { failureMessage(); return; }

#endif