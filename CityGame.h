#pragma once
#include <iostream>
#include <string>
#include <sqlite3.h>
#include <boost/python.hpp>
#include <codecvt>




class City
{
public:
    City(){}
    std::string const &GetName() const;
    void SetName(const std::string&);
    std::string FindCity(const std::string&);
    void UpdateCityExist(const std::string&);
    ~City()
    {
        sqlite3_close(db);
    }


private:
    std::string m_city_name = " ";
    bool is_city_exist = false;
    sqlite3* db = nullptr;
};


