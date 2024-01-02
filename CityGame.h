#pragma once
#include <iostream>
#include <string>
#include <sqlite3.h>


class City
{
public:
    City(){}
    std::string const &GetName() const;
    void SetName(const std::string&);
    int CheckDB();
    ~City()
    {
        sqlite3_close(db);
    }


private:
    std::string m_city_name = " ";
    bool is_city_exist = false;
    sqlite3* db = nullptr;
};


