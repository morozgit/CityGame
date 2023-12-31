#pragma once
#include <string>


class City
{
public:
    City(){}
    std::string const &GetName() const;
    void SetName(const std::string&);


private:
    std::string m_city_name = " ";
};


