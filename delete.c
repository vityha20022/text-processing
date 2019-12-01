#include "delete.h"
#include <string.h>
#include <stdlib.h>
#include "converter.h"
#include "structText.h"

struct Text* delete(struct Text* text){
    int i = 0;
    char* first;
    char* last;
    while (i < text -> number){
        first = converter(text -> arr[i]);
        int j = i + 1;
        while(j < text -> number + 1){
            last = converter(text -> arr[j]);
            if(!strcmp(first, last)){
                free(text -> arr[j]);
                for (int k = j; k < text -> number; k++){
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