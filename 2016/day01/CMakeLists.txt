cmake_minimum_required(VERSION 3.15)

# Create two executables, one for part1 and one for part2.
add_executable(day01_part1 part1.cpp)
target_include_directories(day01_part1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)

add_executable(day01_part2 part2.cpp)
target_include_directories(day01_part2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)
