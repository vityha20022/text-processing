cmake_minimum_required(VERSION 3.15)
project(Test C)

set(CMAKE_C_STANDARD 99)

add_executable(Test test.c readSentence.c readSentence.h converter.c converter.h structText.h delete.c delete.h delete_odd_letter.c delete_odd_letter.h alpha_counter.c alpha_counter.h structSentence.h len_last_word_sort.c len_last_word_sort.h from_string_to_date.c from_string_to_date.h out_put_date.c out_put_date.h printer.c printer.h)