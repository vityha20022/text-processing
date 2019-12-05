#include "structText.h"
#include "out_put_date.h"
#include "from_string_to_date.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

void out_put_date(struct Text* text){
    for(int i = 0; i < text -> number + 1; i++){
        int len_sent = strlen(text->arr[i]);
        char *buf = calloc(len_sent, sizeof(char) + 1);
        //strcpy(buf, text->arr[j]);
        char *istr;
        //istr = strtok(buf, sep);
        int len_word;
        int odd = 0;
        //while (istr != NULL) {


    }

}
