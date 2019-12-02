#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readSentence.h"
#include "converter.h"
#include "structText.h"
#include "delete.h"
#include "delete_odd_letter.h"
#include "alpha_counter.h"



int compare(const void* a, const void* b);

int main() {
    struct Text text;
    struct Text* pointer;
    pointer = &text;
    text.size = 20;
    text.number = 0;
    char **arr;
    arr = calloc(text.size, sizeof(char *));
    text.arr = arr;
    while (1) {
        char *sentence = readSentence();
        if (text.number == text.size) {
            text.size += 20;
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
    //pointer = delete_odd_letter(pointer);
    //pointer = alpha_counter(pointer);
    qsort(text.arr, text.number + 1, sizeof(char*), compare);


    for (int i = 0; i < text.number + 1; i++) {
        printf("%s", pointer->arr[i]);
    }
    for (int i = 0; i < text.number + 1; i++){
        free(text.arr[i]);
    }
    free(text.arr);



}

int compare(const void* a, const void* b){
    char** aa = (char**)a;
    char** bb = (char**)b;
    return strlen(*bb) - strlen(*aa);

}

