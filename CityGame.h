#pragma once
#include <string>


class City
{
public:
    City(){}
    std::string GetName();
    void SetName(std::string);


private:
    std::string m_city_name = " ";
};


