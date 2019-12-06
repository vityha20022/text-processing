#include "delete.h"
#include <string.h>
#include <stdlib.h>
#include "converter.h"
#include "structText.h"

struct Text* delete(struct Text* text){
    int i = 0;
    // создадим переменные под строки, возвращаемые функцией converter, чтобы не потерять адреса
    char* first;
    char* last;
    // последоватлеьно сравниваем каждое предложение со всеми другими и удаляем дубликаты
    while (i < text -> number - 1){
        first = converter(text -> arr[i]);
        int j = i + 1;
        while(j < text -> number){
            last = converter(text -> arr[j]);
            if(!strcmp(first, last)){
                free(text -> arr[j]);
                for (int k = j; k < text -> number - 1; k++){
                    text -> arr[k] = text -> arr[k + 1];
                }
                text -> number--;
                free(last);
            }
            else{
                free(last);
                j++;
            }

        }
        free(first);
        i++;
    }
    return text;
}