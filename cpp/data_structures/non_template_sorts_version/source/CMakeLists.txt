cmake_minimum_required(VERSION 3.20.0)

project(nontemplate_sorts)

add_executable(${PROJECT_NAME} main.cpp)

# Adds the subdirectory called Sorts. Sorts subdirectory also has a CMakeLists.txt file that creates sorts.cpp into a library.
add_subdirectory(Sorts)

# Allows to not include the dir path to Sorts library
target_include_directories(${PROJECT_NAME} PRIVATE Sorts)

# Links library within the build folder
target_link_directories(${PROJECT_NAME} PRIVATE Sorts)

# Links library to project
target_link_libraries(${PROJECT_NAME} Sorts)