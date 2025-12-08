cmake_minimum_required(VERSION 3.15)
project(AoC)

# Create two executables, one for part1 and one for part2.
add_executable(part1 part1.cpp)
target_include_directories(part1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

add_executable(part2 part2.cpp)
target_include_directories(part2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

# Optionally set nice output names (uncomment to change):
# set_target_properties(day01_part1 PROPERTIES OUTPUT_NAME "2016-day01-part1")
# set_target_properties(day01_part2 PROPERTIES OUTPUT_NAME "2016-day01-part2")
