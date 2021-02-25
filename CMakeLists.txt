cmake_minimum_required(VERSION 3.1)

project(daa-practica2)

# Opciones de compilacion
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -fsanitize=address -pedantic-errors -Wall -Wextra -DDEBUG -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Google test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Codigo fuente
include_directories(
  "include"
  "include/instructions" 
)

file(GLOB SRC 
  "src/*.cc"
  "src/instructions/*.cc"
)

file(GLOB TESTS 
  "tests/*.cc"
)

# Compilacion - enlazado
add_executable(ram_sim ${SRC})
add_executable(tests
  ${TESTS}
  src/tape.cc
  src/program_counter.cc
 )

target_link_libraries(tests ${GTEST_LIBRARIES} pthread)