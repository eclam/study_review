cmake_minimum_required(VERSION 3.20.0)

project(c_study_review)

add_executable(${PROJECT_NAME} main.c)

# Adds the subdirectory called Sorts. Sorts subdirectory also has a CMakeLists.txt file that creates sorts.cpp into a library.
add_subdirectory(C_StudyReview)

# Allows to not include the dir path to Sorts library
target_include_directories(${PROJECT_NAME} PRIVATE C_StudyReview)

# Links library within the build folder
target_link_directories(${PROJECT_NAME} PRIVATE C_StudyReview)

# Links library to project
target_link_libraries(${PROJECT_NAME} C_StudyReview)