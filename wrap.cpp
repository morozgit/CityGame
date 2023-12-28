#include "CityGame.h"

using namespace boost::python;
BOOST_PYTHON_MODULE(city_game)
{
    class_<City>( "City" )
    .def("GetName", &City::GetName, return_value_policy<copy_const_reference>())
    ;
}