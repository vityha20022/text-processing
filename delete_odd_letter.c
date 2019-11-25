#include "delete_odd_letter.h"
#include "structText.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct Text* delete_odd_letter(struct Text* text){
    char sep[2] = " ,";
    int len_sent = strlen(text -> arr[0]);
    char* buf = malloc(len_sent * sizeof(char));
    strcpy(buf, text -> arr[0]);
    char* istr;
    istr = strtok(buf, sep);
    int len_word = strlen(istr);
    int odd = 0;
    while(istr != NULL){
        len_word = strlen(istr);
        int count = 0;
        for(int i = 0; i < len_word; i++){
            if(isalpha(istr[i])){
                count++;
            }
        }
        if(count % 2 == 0){
            odd++;
        }
        istr = strtok(NULL, sep);


    }
    if(odd == 0){
        free(text -> arr[0]);
        for (int i = 0; i < text -> n; i++){
            text -> arr[i] = text-> arr [i + 1];
        }
        text -> n--;
    }
    free(buf);
    return text;
};
