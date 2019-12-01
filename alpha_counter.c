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
        char *buf = malloc(len_sent * sizeof(char) + 1);
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
            int all_len = strlen(istr) + strlen(counter);
            char* new_str = malloc(all_len);
            if (count > 0){
                strcpy(new_str, counter);
            }
            strcat(new_str, istr);
            printf("%s ", new_str);

            istr = strtok(NULL, sep);


        }
        j++;
    }
    return text;

}