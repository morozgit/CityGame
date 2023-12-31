cmake_minimum_required(VERSION 3.12)
project(CityGame LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find python and Boost - both are required dependencies
find_package(PythonLibs REQUIRED)
find_package(Boost COMPONENTS python REQUIRED)

# Without this, any build libraries automatically have names "lib{x}.so"
set(CMAKE_SHARED_MODULE_PREFIX "")

# Add a shared module - modules are intended to be imported at runtime.
# - This is where you add the source files
add_library(classes MODULE CityGame.cpp)

# Set up the libraries and header search paths for this target
target_link_libraries(classes ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
target_include_directories(classes PRIVATE ${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

# Set the output directory for the shared module
set_target_properties(classes PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
