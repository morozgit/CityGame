#include "CityGame.h"


std::string const &City::GetName() const
{
    return m_city_name;
}
void City::SetName(const std::string &name)
{
    m_city_name = name;
}

std::wstring toUpper(const std::wstring& str) {
    if (str.empty()) {
        std::wcerr << L"Введенная строка пуста." << std::endl;
        return L"";
    }

    std::wstring upperStr;
    std::locale loc;

    for (wchar_t ch : str) {
        upperStr += std::towupper(ch);
    }

    return upperStr;
}


std::string City::FindCity(const std::string& last_letter)
{
    std::cout << last_letter << std::endl;
    // sqlite3* db;
    int rc = sqlite3_open("russia_city.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Не удалось открыть базу данных: " << sqlite3_errmsg(db) << std::endl;
        return sqlite3_errmsg(db);
    }
    std::string query = "SELECT name FROM Cities WHERE is_city_exist = 0 AND name LIKE '" + last_letter + "%' LIMIT 1;";

    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Ошибка при подготовке запроса: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return sqlite3_errmsg(db);
    }
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) 
    {
        std::string cityName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        std::cout << "Найден город: " << cityName << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return cityName;
    }
    else {
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return "Город не найден.";
    }

}

void City::UpdateCityExist(const std::string& city_name)
{
    // sqlite3* db;
    int rc = sqlite3_open("russia_city.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Не удалось открыть базу данных: " << sqlite3_errmsg(db) << std::endl;
    }
    std::string updateQuery = "UPDATE Cities SET is_city_exist = 1 WHERE name = '" + city_name + "';";
    rc = sqlite3_exec(db, updateQuery.c_str(), nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK) {
        std::cerr << "Ошибка при выполнении запроса на обновление: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Флаг isCityExist успешно установлен в true для города " << city_name << std::endl;
    }
    sqlite3_close(db);
}

int City::CheckCityExist(const std::string& city_name)
{
    std::cout << city_name << std::endl;
    int rc = sqlite3_open("russia_city.db", &db);

    if (rc != SQLITE_OK) {
        std::cerr << "Не удалось открыть базу данных: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    }
    std::string query = "SELECT name, is_city_exist FROM Cities WHERE name = '" + city_name + "';";

    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Ошибка при подготовке запроса: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 0;
    }
    rc = sqlite3_step(stmt);

    if (rc == SQLITE_ROW) 
    {
        int is_city_exist = sqlite3_column_int(stmt, 1);
        std::cout << is_city_exist << std::endl;
        if(is_city_exist == 1){
            std::cout << "Город был назван " << city_name << std::endl;
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 1;
        }
        else {
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            return 0;
        }
    }
}

using namespace boost::python;

BOOST_PYTHON_MODULE(classes)
{
    class_<City>("City")
        .def("GetName", &City::GetName, return_value_policy<copy_const_reference>())
        .def("SetName", &City::SetName)
        .def("FindCity", &City::FindCity)
         .def("UpdateCityExist", &City::UpdateCityExist)
        .def("CheckCityExist", &City::CheckCityExist)
    ;
}