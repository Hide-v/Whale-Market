#include "../../include/good/good.h"
#include "../../include/config.h"
#include "../../include/tools/info.h"
#include <fstream>
#include <iomanip>
#include <ios>
#include <string>

static std::string filepath = "../data/good.dat";

static Good goods[MAX_GOOD];
static int totalgood = 0;
static const std::string stateName[] = {"Selling", "Sold", "Banned"};
static const std::string header = "|ID         |Name       |Price      |Date       |Seller     |State      |";
static const std::string divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";

void pullGoods()
{
    totalgood = 0;
    std::ifstream FILE;
    FILE.open(filepath, std::ios::binary | std::ios::in);
    if(FILE.is_open())
    {
        while(FILE.read(reinterpret_cast<char*>(&goods[totalgood]), sizeof(Good)) && totalgood < MAX_USER)
        {
            totalgood++;
        }
    }
    FILE.close();
}

void pushGoods()
{
    std::ofstream FILE;
    FILE.open(filepath, std::ios::binary | std::ios::out);
    if (FILE.is_open())
    {
        for (int i = 0; i < totalgood; i++)
        {
            FILE.write(reinterpret_cast<const char*>(&goods[i]), sizeof(Good));
        }
    }
    FILE.close();
}

Good* getGood(int idex)
{
    return goods + idex;
}

int addGood(Good* g)
{
    if (totalgood == MAX_USER)             // 确定用户未满
        return 0;
    getID(g->id, 'U');      // 获取ID
    getDate(g->date);                  // 获取日期
    g->state = SELLING;
    goods[totalgood++] = *g;            // 存入数组
    return 1;
}

void goodInfo(int i)
{
    std::cout << "ID:            | " << goods[i].id << '\n';
    std::cout << "Name:          | " << goods[i].name << '\n';
    std::cout << "Description:   | " << goods[i].description << '\n';
    std::cout << "Date:          | " << goods[i].date << '\n';
    std::cout << "Price:         | " << goods[i].price << '\n';
    std::cout << "Seller:        | " << goods[i].seller_id << '\n';
    std::cout << "State:         | " << stateName[goods[i].state] << '\n';
}

int searchGoodID(std::string id)
{
    for (int i = 0; i < totalgood; i++)
    {
        if (id.compare(goods[i].id))
            return i;
    }
    return -1;
}

int deleteGood(std::string id, std::string who)
{
    int idx = searchGoodID(id);
    if (idx == -1)  return 0;
    if (!(who.empty()) && who.compare(goods[idx].seller_id))    return 0;
    goods[idx].state = BANNED;
    return 1;
}

/**
 * @brief 打印单个商品作为表格的一行
 * 
 * @param i 用户下标
 */
static void printGood(int i)
{
    std::cout << "| " << std::setw(10)  << std::left << goods[i].id << \
                 "| " << std::setw(10) << std::left << goods[i].name << \
                 "| " << std::setw(10) << std::left << goods[i].price << \
                 "| " << std::setw(10) << std::left << goods[i].date << \
                 "| " << std::setw(10) << std::left << goods[i].seller_id << \
                 "| " << std::setw(10) << std::left << stateName[goods[i].state] << std::endl;
}

void printGoods()
{
    print_header
    for (int i = 0; i < totalgood; i++)
    {
        printGood(i);
        print_divide
    }
}

void searchGoodName4Buyer(std::string name)
{
    print_header
    for (int i = 0; i < totalgood; i++)
    {
        if (goods[i].state == SELLING && goods[i].name.find(name))
        {
            printGood(i);
            print_divide
        }
    }
}

void searchGoodName4Admin(std::string name)
{
    print_header
    for (int i = 0; i < totalgood; i++)
    {
        if (goods[i].name.find(name))
        {
            printGood(i);
            print_divide
        }
    }
}

void printGoods4Seller(std::string id)
{
    print_header
    for (int i = 0; i < totalgood; i++)
    {
        if (id.compare(goods[i].name)  == 0)
        {
            printGood(i);
            print_divide
        }
    }
}

void printGoods4Buyer(std::string id)
{
    print_header
    for (int i = 0; i < totalgood; i++)
    {
        if (goods[i].state == SELLING)
        {
            printGood(i);
            print_divide
        }
    }
}