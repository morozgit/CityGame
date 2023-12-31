#include "CityGame.h"


std::string City::GetName()
{
    return m_city_name;
}
void City::SetName(std::string name)
{
    m_city_name = name;
}

#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(classes)
{
    class_<City>("City")
        .def("GetName", &City::GetName)
        .def("SetName", &City::SetName)
    ;
}