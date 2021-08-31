cmake_minimum_required(VERSION 3.17)
project(Turing_Automata C)

set(CMAKE_C_STANDARD 99)

add_executable(Turing_Automata main.c turing_automata.h turing_automata.c)