#include "../../include/order/order.h"
#include "../../include/tools/info.h"
#include <fstream>
#include <iomanip>

static const std::string filepath = "../data/order.dat";
static Order orders[MAX_ORDER];
static int totalorder = 0;

static const std::string header = "|ID         |Good       |Price      |Date       |Seller     |Buyer      |";
static const std::string divide = "+-----------+-----------+-----------+-----------+-----------+-----------+";

void pullOrders()
{
    totalorder = 0;
    std::ifstream FILE;
    FILE.open(filepath, std::ios::binary | std::ios::in);
    if(FILE.is_open())
    {
        while(FILE.read(reinterpret_cast<char*>(&orders[totalorder]), sizeof(Order)) && totalorder < MAX_USER)
        {
            totalorder++;
        }
    }
    FILE.close();
}

void pushOrders()
{
    std::ofstream FILE;
    FILE.open(filepath, std::ios::binary | std::ios::out);
    if (FILE.is_open())
    {
        for (int i = 0; i < totalorder; i++)
        {
            FILE.write(reinterpret_cast<const char*>(&orders[i]), sizeof(Order));
        }
    }
    FILE.close();
}

int addOrder(Order* o)
{
    if (totalorder == MAX_ORDER)
        return 0;
    getID(o->id, 'O');
    getDate(o->date);
    orders[totalorder++] = *o;
    return 1;
}

static void printOrder(int i)
{
    std::cout << "| " << std::setw(10)  << std::left << orders[i].id << \
        "| " << std::setw(10) << std::left << orders[i].good_id << \
        "| " << std::setw(10) << std::left << orders[i].price << \
        "| " << std::setw(10) << std::left << orders[i].date << \
        "| " << std::setw(10) << std::left << orders[i].seller_id << \
        "| " << std::setw(10) << std::left << orders[i].buyer_id << std::endl;
}

void printOrders()
{
    print_header
    for (int i = 0; i < totalorder; i++)
    {
        printOrder(i);
        print_divide
    }
}

void printOrders4Seller(std::string id)
{
    print_header
    for (int i = 0; i < totalorder; i++)
    {
        if (id.compare(orders[i].seller_id) == 0)
        {
            printOrder(i);
            print_divide
        }
    }
}

void printOrders4Buyer(std::string id)
{
    print_header
    for (int i = 0; i < totalorder; i++)
    {
        if (id.compare(orders[i].buyer_id) == 0)
        {
            printOrder(i);
            print_divide
        }
    }
}