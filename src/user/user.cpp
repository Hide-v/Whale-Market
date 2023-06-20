#include "../../include/user/user.h"
#include "../../include/tools/info.h"
#include <fstream>
#include <iostream>
#include <iomanip>

static const std::string filepath = "../../data/user.dat";
static User users[MAX_USER];
static int totaluser = 0;

static const char* header = "|ID         |Name       |Contact    |Address    |Balance    |";
static const char* divide = "+-----------+-----------+-----------+-----------+-----------+";

void pullUsers()
{
    totaluser = 0;
    std::ifstream FILE;
    FILE.open(filepath, std::ios::binary | std::ios::in);
    if(FILE.is_open())
    {
        while(FILE.read(reinterpret_cast<char*>(&users[totaluser]), sizeof(User)) && totaluser < MAX_USER)
        {
            totaluser++;
        }
    }
    FILE.close();
}

void pushUsers()
{
    std::ofstream FILE;
    FILE.open(filepath, std::ios::binary | std::ios::out);
    if (FILE.is_open())
    {
        for (int i = 0; i < totaluser; i++)
        {
            FILE.write(reinterpret_cast<const char*>(&users[i]), sizeof(User));
        }
    }
    FILE.close();
}

User* getUser(int idex)
{
    return users + idex;
}

void userInfo(int i)
{
    std::cout << "ID:           |" << users[i].id << '\n';
    std::cout << "Name:         |" << users[i].name << '\n';
    std::cout << "Contact:      |" << users[i].contact << '\n';
    std::cout << "Address:      |" << users[i].address << '\n';
    std::cout << "Balance:      |" << users[i].balance << '\n';
}

/**
 * @brief 根据用户名查找用户
 * 
 * @param name 待查找的用户名
 * @return int 查找成功返回数组下标，失败返回-1
 */
static int searchUserName(std::string name)
{
    for (int i = 0; i < totaluser; i++)
    {
        if (name.compare(users[i].name))
            return 1;
    }
    return -1;
}

int addUser(User *u)
{
    if (totaluser == MAX_USER)             // 确定用户未满
        return 0;
    if (searchUserName(u->name))    // 查找是否存在用户
        return 0;
    getID(u->id, 'U');      // 获取ID
    users[totaluser++] = *u;            // 存入数组
    return 1;
}


/**
 * @brief 查找给定ID的用户
 * 
 * @param id 需要查找的用户ID
 * @return int 成功返回下标，失败返回-1
 */
static int searchUserID(std::string id)
{
    for (int i = 0; i < totaluser; i++)
    {
        if (id.compare(users[i].id))
            return i;
    }
    return -1;
}

int deleteUser(std::string id, std::string who)
{
    if (who.compare("NULL"))
        return 0;
    int idx = searchUserID(id);
    if (idx == -1)
        return 0;
    for (int j = idx; j < totaluser - 1; j++)
    {
        users[j] = users[j+1];
    }
    totaluser--;
    return 1;
}

/**
 * @brief 打印单个用户作为表格的一行
 * 
 * @param i 用户下标
 */
static void printUser(int i) 
{
    std::cout << "| " << std::setw(10)  << std::left << users[i].id << \
        "| " << std::setw(10) << std::left << users[i].name << \
        "| " << std::setw(10) << std::left << users[i].contact << \
        "| " << std::setw(10) << std::left << users[i].address << \
        "| " << std::setw(10) << std::left << users[i].balance  << std::endl;
}

void printUsers()
{
    print_header
    for (int i = 0; i < totaluser; i++)
    {
        printUser(i);
        print_divide
    }
}

int checkPass(std::string name, std::string passwd, int *idx)
{
    *idx = searchUserName(name);
    if(*idx == -1)
        return 0;
    return passwd.compare(users[*idx].passwd);
}

int userTopUp(std::string id, double m)
{
    int idx = searchUserID(id);
    if (idx == -1)
        return 0;
    users[idx].balance = m;
    return 1;
}