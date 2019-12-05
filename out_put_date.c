#include "structText.h"
#include "out_put_date.h"
#include "from_string_to_date.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void out_put_date(struct Text* text){
    int no_space = 0;
    for(int i = 0; i < text -> number + 1; i++){
        time_t now_time;
        now_time = time(NULL);
        int len_sent = strlen(text->arr[i]);
        char *buf = calloc(len_sent + 1, sizeof(char));
        strcpy(buf, text->arr[i]);
        char *istr;
        char *istr2;
        istr = strtok(buf, " ");
        int count = 0;
        // узнаем содержит ли предложение дату формата dd/mm/yyyy
        while (istr != NULL) {
            if(from_string_to_date(istr) != -1){
                count++;
            }
            istr = strtok(NULL, buf);

        }
        free(buf);
        if (count > 0){
            buf = calloc(len_sent + 1, sizeof(char));
            strcpy(buf, text->arr[i]);
            istr2 = strtok(buf, " ");
            while(istr2 != NULL){
                if (from_string_to_date(istr2) > now_time){
                    char red[25] = "\033[0;31m";
                    char none[7] = "\033[0m";

                    strcat(red, istr2);
                    strcat(red, none);
                    if(no_space == 0){
                        printf("%s", red);
                    }
                    printf(" %s", red);
                    istr2 = strtok(NULL, " ");
                    continue;

                }
                if(no_space == 0){
                    printf("%s", istr2);
                }
                printf(" %s", istr2);
                istr2 = strtok(NULL, " ");
                no_space = 1;

            }

        }


    }

}
