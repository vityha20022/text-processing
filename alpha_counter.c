#include "alpha_counter.h"
#include <stdlib.h>
#include <string.h>
#include "structText.h"
#include <ctype.h>
#include <stdio.h>


struct Text* alpha_counter(struct Text* text){
    char* sep =  " ";
    int j = 0;
    while(j < text -> number + 1) {
        int len_sent = strlen(text->arr[j]);
        char* buf = calloc(len_sent, sizeof(char) + 1);
        char* new_arr = calloc(len_sent,sizeof(char) + 1);
        strcpy(buf, text->arr[j]);
        char *istr;
        istr = strtok(buf, sep);
        int len_word;
        while (istr != NULL) {
            len_word = strlen(istr);
            int count = 0;
            for (int i = 0; i < len_word; i++) {
                if (isalpha(istr[i])) {
                    count++;
                }
            }
            char* counter = calloc(17,sizeof(char));
            sprintf(counter, "%d", count);
            int all_len = strlen(istr) + strlen(counter) + 2;
            char* new_str = calloc(all_len, sizeof(char));
            if(buf[0] == ' ') {
                strcat(new_str, " ");

                if (count > 0) {
                    strcat(new_str, counter);
                }
                strcat(new_str, istr);
                if (strlen(new_arr) + strlen(new_str) >= len_sent) {
                    len_sent += len_sent;
                    new_arr = realloc(new_arr, len_sent);
                }
                strcat(new_arr, new_str);
                free(new_str);
                free(counter);


                istr = strtok(NULL, sep);
            }
            else{
                if (count > 0){
                    strcpy(new_str, counter);
                }
                strcat(new_str, istr);
                if(istr[strlen(istr) - 1] != '.'){
                    strcat(new_str, " ");
                }
                if (strlen(new_arr) + strlen(new_str) >= len_sent){
                    len_sent+= len_sent;
                    new_arr = realloc(new_arr, len_sent);
                }
                strcat(new_arr, new_str);
                free(new_str);
                free(counter);


                istr = strtok(NULL, sep);
            }


        }
        free(buf);
        free(text -> arr[j]);
        text -> arr[j] = new_arr;
        j++;
    }
    return text;

}