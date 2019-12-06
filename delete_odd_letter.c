#include "delete_odd_letter.h"
#include "structText.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Text* delete_odd_letter(struct Text* text){
    char sep[2] = " ,";
    int j = 0;
    while(j < text -> number) {
        int len_sent = strlen(text->arr[j]);
        char *buf = calloc(len_sent + 1, sizeof(char));
        strcpy(buf, text->arr[j]);
        char *istr;
        istr = strtok(buf, sep);
        int len_word;
        int odd = 0;
        // если переменная odd осталась равна 0, значит предложение следует удалить
        while (istr != NULL) {
            len_word = strlen(istr);
            int count = 0;
            for (int i = 0; i < len_word; i++) {
                if (isalpha(istr[i])) {
                    count++;
                }
            }
            if (count % 2 == 0) {
                odd++;
            }
            istr = strtok(NULL, sep);


        }
        // отдельный случай для единственного прдложения, дабы при сдвиге предложений не произошел сегфолт
        if (odd == 0 && text -> number == 0){
            free(text -> arr[j]);
            text ->number--;
            free(buf);
            break;
        }
        if (odd == 0 && text -> number != 0) {
            //убираем незначащий пробел в случае, если удаляется предложение начинающееся не с пробела
            if (text -> arr[j][0] != ' '){
                for (int i = 0; i < strlen(text -> arr[j + 1]); i++){
                    text -> arr[j + 1][i] = text -> arr[j + 1][i + 1];
                }
            }

            free(text->arr[j]);
            // сдвигаем предложения
            for (int i = j; i < text-> number - 1; i++) {
                text->arr[i] = text->arr[i + 1];
            }

            text->number--;
            free(buf);
        }
        else {
            free(buf);
            j++;
        }
    }
    return text;
};
