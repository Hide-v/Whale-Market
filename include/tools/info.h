// info.h
#ifndef _INFO_H_
#define _INFO_H_
#include <iostream>

/**
 * @brief 生成一个给定类型ID
 * 
 * @param dest 储存ID的目标字符串
 * @param type ID类型，U-用户，G-商品，O-订单
 */
void genID(std::string dest, char type);

/**
 * @brief 获取当前日期
 * 
 * @param dest 储存日期的目标字符串
 */
void getDate(std::string dest);

#endif