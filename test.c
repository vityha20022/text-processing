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


int compare(const void* a, const void* b);

int main() {
    struct Text text;
    struct Text* pointer;
    pointer = &text;
    text.size = 20;
    text.number = 0;
    char **arr;
    arr = calloc(text.size, sizeof(char *));
    text.arr = arr;
    while (1) {
        char *sentence = readSentence();
        if (text.number == text.size) {
            text.size += 20;
            // добавить проверку реалока
            text.arr = realloc(text.arr, sizeof(char *) * text.size);
        }
        if (strchr(sentence, '\n')) {
            free(sentence);
            break;
        }
        text.arr[text.number] = sentence;
        text.number++;

    }
    text.number--;

    pointer = delete(pointer);
    //pointer = delete_odd_letter(pointer);
    //pointer = alpha_counter(pointer);

    struct Sentence* sentence = malloc(text.number + 1 * sizeof(struct Sentence));
    for (int i = 0; i < text.number + 1; i++){
        int len_memmory = strlen(text.arr[i]) + 2;
        sentence[i].sent = calloc(len_memmory, sizeof(char));
        strcpy(sentence[i].sent, text.arr[i]);
        if(sentence[i].sent[0] != ' '){
            int len = strlen(sentence[i].sent);
            for(int k = len; k >= 0; k--){
                sentence[i].sent[k + 1] = sentence[i].sent[k];
            }
            sentence[i].sent[0] = ' ';
        }
    }

    for(int i = 0; i < text.number + 1; i++){
        char* istr;
        char* buf;
        istr = strtok(text.arr[i], " ");
        while (istr != NULL){
            buf = istr;
            istr = strtok(NULL, " ");
        }
        sentence[i].len_last_word = strlen(buf);
    }
    for (int i = 0; i < text.number + 1; i++){
        free(text.arr[i]);
    }


    qsort(sentence, text.number + 1, sizeof(struct Sentence), compare);

    for(int i = 0; i < strlen(sentence[0].sent); i++){
        sentence[0].sent[i] = sentence[0].sent[i + 1];
    }

    for (int i = 0; i < text.number + 1; i++){
        pointer -> arr[i] = &sentence->sent[i];
    }

    for (int i = 0; i < text.number + 1; i++) {
        printf("%s", text.arr[i]);
    }

    for (int i = 0; i < text.number + 1; i++){
        free(sentence[i].sent);
    }
    free(text.arr);



}

int compare(const void* a, const void* b){

    return ((struct Sentence*)a) -> len_last_word - ((struct Sentence*)b) -> len_last_word;

}

