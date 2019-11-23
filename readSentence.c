
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readSentence.h"

char* readSentence(){
    int size = 20;
    int n = 0;
    char symbol = getchar();
    char* sentence = malloc(size * sizeof(char));
    sentence[n] = symbol;
    n++;
    while(!strchr(".\n", symbol)) {
        symbol = getchar();
        if (n == size) {
            size += 20;
            sentence = realloc(sentence, size * sizeof(char));
        }
        sentence[n] = symbol;
        n++;
    }
    sentence[n] = '\0';
    return sentence;
}