cmake_minimum_required(VERSION 3.15)
project(Test C)

set(CMAKE_C_STANDARD 99)

add_executable(Test test.c test.c readSentence.c readSentence.h converter.c converter.h structText.h delete.c delete.h delete_odd_letter.c delete_odd_letter.h alpha_counter.c alpha_counter.h structSentence.h)