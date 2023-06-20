#ifndef _USER_H_
#define _USER_H_
#include "../config.h"
#include <string>

typedef struct {
    std::string id;
    std::string name;
    std::string passwd;
    std::string contact;
    std::string address;
    double balance;
}User;

/**
 * @brief 从外部文件导入用户信息
 * 
 */
void pullUsers();

/**
 * @brief 将用户信息导出到外部文件
 * 
 */
void pushUsers();

/**
 * @brief 获取用户对象
 * 
 * @param idex 用户在的数组下标
 * @return User* 指向对应用户的指针
 */
User* getUser(int idex);

/**
 * @brief 打印详细的用户信息
 * 
 * @param i 用户的数组下标
 */
void userInfo(int i);

/**
 * @brief 添加新用户
 * 
 * @param u 待添加的用户指针
 * @return 添加成功返回1，添加失败返回0
 */
int addUser(User* u);

/**
 * @brief 删除给定ID的用户
 * 
 * @param id 待删除用户的id
 * @param who 删除操作执行者的id，管理员为null
 * @return int 删除成功返回1，失败返回0
 */
int deleteUser(std::string id, std::string who);

/**
 * @brief 打印所有用户的信息
 * 
 */
void printUsers();

/**
 * @brief 检查用户名和密码是否匹配
 * 
 * @param name 用户名
 * @param passwd 密码
 * @param idx 如果成功，通过指针返回用户的下标
 * @return int 匹配成功返回1，失败返回0
 */
int checkPass(std::string name, std::string passwd, int* idx);

/**
 * @brief 用户充值 
 * 
 * @param id 待充值用户id
 * @param m 充值数额
 * @return 充值成功返回1，失败返回0
 */
int userTopUp(std::string id, double m);

#endif