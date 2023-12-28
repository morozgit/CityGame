#include <boost/python.hpp>
#include <string>

class City
{
    public:
    City() = default;
    City(const std::string& city_name) : m_city_name(city_name) {}
    std::string const& GetName() const;
    ~City() = default;

    private:
    std::string m_city_name;
};