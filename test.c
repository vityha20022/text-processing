#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readSentence.h"
#include "converter.h"
#include "structText.h"
#include "delete.h"





int main() {
    struct Text text;
    struct Text* pointer;
    pointer = &text;
    text.size = 20;
    text.n = 0;
    char **arr;
    arr = malloc(text.size * sizeof(char *));
    text.arr = arr;
    while (1) {
        char *sentence = readSentence();
        if (text.n == text.size - 1) {
            text.size += 20;
            // добавить проверку реалока
            text.arr = realloc(text.arr, sizeof(char *) * text.size);
        }
        if (strchr(sentence, '\n')) {
            free(sentence);
            break;
        }
        text.arr[text.n] = sentence;
        text.n++;

    }
    text.n--;

    pointer = delete(pointer);


    for (int i = 0; i < text.n + 1; i++) {
        printf("%s", pointer->arr[i]);
    }
    for (int i = 0; i < text.n + 1; i++){
        free(text.arr[i]);
    }
    free(arr);


}


