#include "../../include/tools/hint.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <ctime>
#include <time.h>

static const std::string filepath = "../data/id.txt";

void getID(std::string dest, char type)
{
    int uid = 0, gid = 0, oid = 0;
    std::fstream FILE;
    FILE.open(filepath, std::ios::in);
    if(FILE.is_open())
    {
        FILE >> uid >> gid >> oid;
        FILE.close();
    }
    int id;
    switch (type) {
        case 'U' : id = uid++; break;
        case 'G' : id = gid++; break;
        case 'O' : id = oid++; break;
    }
    std::ostringstream oss;
    oss << type << std::setfill('0') << std::setw(5) << id;
    dest = oss.str();

    FILE.open(filepath, std::ios::out | std::ios::trunc);
    FILE << uid << " " << gid << " " << uid;
    FILE.close();
}

void getDate(std::string dest)
{
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm localtime;
    localtime_s(&localtime, &currentTime);
    
    std::ostringstream oss;
    oss << localtime.tm_year + 1900 << '-' << localtime.tm_mon + 1 << '-' << localtime.tm_mday;
    dest = oss.str();
}