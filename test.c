#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readSentence.h"
#include "converter.h"
#include "structText.h"
#include "delete.h"
#include "delete_odd_letter.h"
#include "alpha_counter.h"
#include "structSentence.h"
#include "len_last_word_sort.h"
#include "from_string_to_date.h"
#include "out_put_date.h"


int main() {
    struct Text text;
    struct Text* pointer;
    pointer = &text;
    text.size = 50;
    text.number = 0;
    char **arr;
    arr = calloc(text.size, sizeof(char *));
    text.arr = arr;
    int input;
    while (1) {
        char *sentence = readSentence();
        if (text.number == text.size) {
            text.size += 50;
            // добавить проверку реалока
            text.arr = realloc(text.arr, sizeof(char *) * text.size);
        }
        if (strchr(sentence, '\n')){
            free(sentence);
            break;
        }
        text.arr[text.number] = sentence;
        text.number++;

    }


    pointer = delete(pointer);
    printf("Выберите одно из доступных действий:\n");
    printf(" 1. Вывести все предложения в которых есть даты в формате “DD/MM/YYYY”, даты которые еще не наступили будут выделины красным цветом.\n");
    printf(" 2. Удалить все предложения в которых каждое слово содержит нечетное количество букв.\n");
    printf(" 3. Преобразовать предложения так, чтобы перед каждым словом стояло количество букв в нем.\n");
    printf(" 4. Отсортировать предложения по возрастанию длины последнего слова.\n");
    printf(" 5. Выйти\n\n");
    printf ("    Enter your choice: ");
    scanf("%d", &input);
    while(1) {
        switch (input) {
            case 1:
                out_put_date(pointer);
                printf("\n\n ==================================================================================");
                printf("\n\n     Enter your choice: ");
                break;
            case 2:
                pointer = delete_odd_letter(pointer);
                for (int i = 0; i < text.number; i++) {
                    printf("%s", text.arr[i]);
                }
                printf("\n\n ==================================================================================");
                printf("\n\n     Enter your choice: ");
                break;
            case 3:
                pointer = alpha_counter(pointer);
                for (int i = 0; i < text.number; i++) {
                    printf("%s", text.arr[i]);
                }
                printf("\n\n ==================================================================================");
                printf("\n\n     Enter your choice: ");
                break;
            case 4:
                pointer = len_last_word_sort(pointer);
                for (int i = 0; i < text.number; i++) {
                    printf("%s", text.arr[i]);
                }
                printf("\n\n ==================================================================================");
                printf("\n\n     Enter your choice: ");
                break;
            case 5:
                for (int i = 0; i < text.number; i++) {
                    free(text.arr[i]);
                }
                free(text.arr);
                return 0;
            default:
                printf("Вы ввели неверное значение, попробуйте еще раз.");
                printf("\n\n ==================================================================================");
                printf("\n\n     Enter your choice: ");
                break;





        }
        scanf("%d", &input);
    }


}



