cmake_minimum_required(VERSION 3.12)
project(CityGame)

# Найти библиотеку Boost
find_package(Boost REQUIRED COMPONENTS python)

# Вывести информацию о найденных компонентах Boost
message(STATUS "Boost version: ${Boost_VERSION}")
message(STATUS "Boost include dirs: ${Boost_INCLUDE_DIRS}")
message(STATUS "Boost libraries: ${Boost_LIBRARIES}")

# Указать директории для поиска заголовочных файлов Boost
include_directories(${Boost_INCLUDE_DIRS})

# Указать директории для поиска заголовочных файлов Python
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

# Создать исполняемый файл
add_executable(CityGame CityGame.h CityGame.cpp main.cpp wrap.cpp)

target_include_directories(CityGame PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


# Линковка с библиотекой Boost.Python
target_link_libraries(CityGame ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
