#include <stdlib.h>
#include "len_last_word_sort.h"
#include <string.h>
#include "structText.h"
#include "structSentence.h"
int compare(const void* a, const void* b);
struct Text* len_last_word_sort(struct Text* text){
    // заполняем массив структур с полем len_last_word и приовдим все предложения к одному виду
    struct Sentence* sentence = malloc((text -> number + 1) * sizeof(struct Sentence));
    for (int i = 0; i < text -> number + 1; i++){
        int len_memmory = strlen(text -> arr[i]) + 2;
        sentence[i].sent = calloc(len_memmory, sizeof(char));
        strcpy(sentence[i].sent, text -> arr[i]);
        if(sentence[i].sent[0] != ' '){
            int len = strlen(sentence[i].sent);
            for(int k = len; k >= 0; k--){
                sentence[i].sent[k + 1] = sentence[i].sent[k];
            }
            sentence[i].sent[0] = ' ';
        }
    }

    // заполняем поле len_last_word в каждом из предложений
    for(int i = 0; i < text -> number + 1; i++){
        char* istr;
        char* buf;
        istr = strtok(text -> arr[i], " ");
        while (istr != NULL){
            buf = istr;
            istr = strtok(NULL, " ");
        }
        sentence[i].len_last_word = strlen(buf);
    }

    // очищаем старый массив для дальнейшей перезаписи в него отсортированного нового массива
    for (int i = 0; i < text -> number + 1; i++){
        free(text -> arr[i]);
    }

    // производим сортировку
    qsort(sentence, text -> number + 1, sizeof(struct Sentence), compare);


    // убираем незначащий пробел добавленный ранее из первого предложения
    for(int i = 0; i < strlen(sentence[0].sent); i++){
        sentence[0].sent[i] = sentence[0].sent[i + 1];
    }
    // перезаписываем в исходный массив отсортированный массив
    for(int i = 0; i < text -> number + 1; i++){
        text -> arr[i] = sentence[i].sent;
    }
    free(sentence);
    return text;
};

int compare(const void* a, const void* b){

    return ((struct Sentence*)a) -> len_last_word - ((struct Sentence*)b) -> len_last_word;

};
