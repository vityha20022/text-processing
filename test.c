#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "readSentence.h"
#include "converter.h"
#include "structText.h"
#include "delete.h"
#include "delete_odd_letter.h"
#include "alpha_counter.h"
#include "structSentence.h"
#include "len_last_word_sort.h"
#include "from_string_to_date.h"
#include "out_put_date.h"


int main() {
    struct Text text;
    struct Text* pointer;
    pointer = &text;
    text.size = 50;
    text.number = 0;
    char **arr;
    arr = calloc(text.size, sizeof(char *));
    text.arr = arr;
    while (1) {
        char *sentence = readSentence();
        if (text.number == text.size) {
            text.size += 50;
            // добавить проверку реалока
            text.arr = realloc(text.arr, sizeof(char *) * text.size);
        }
        if (strchr(sentence, '\n')) {
            free(sentence);
            break;
        }
        text.arr[text.number] = sentence;
        text.number++;

    }
    text.number--;

    pointer = delete(pointer);
    out_put_date(pointer);




    for (int i = 0; i < text.number + 1; i++) {
        printf("%s\n", text.arr[i]);
    }


    for (int i = 0; i < text.number + 1; i++){
        free(text.arr[i]);
    }
    free(text.arr);




}



