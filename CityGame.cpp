#include "CityGame.h"


std::string const &City::GetName() const
{
    return m_city_name;
}
void City::SetName(const std::string &name)
{
    m_city_name = name;
}
int City::CreateDB(const char* bd_name)
{
    int rc = sqlite3_open(bd_name, &db);
    return rc;
}



#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(classes)
{
    class_<City>("City")
        .def("GetName", &City::GetName, return_value_policy<copy_const_reference>())
        .def("SetName", &City::SetName)
        .def("CreateDB", &City::CreateDB)
    ;
}