#ifndef _MENU_H_
#define _MENU_H_
#include "../../include/config.h"

typedef enum {MAIN, ADMIN, USER, BUYER, SELLER, INFO, MODIFY, GOOD} Menu;
extern const int optionNum[];

/**
 * @brief 菜单的作用是给出提示信息并获取用户输入
 * 
 * @param type 菜单类型
 * @return int 用户的有效输入
 */
int menu(Menu type);

#endif