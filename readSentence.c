
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readSentence(){
    int size = 20;
    char* sentence = malloc(size * sizeof(char));
    int n = 0;
    char symbol = getchar();
    sentence[n] = symbol;
    n++;
    while(!strchr(".\n", symbol)) {
        symbol = getchar();
        if (n == size - 1) {
            size += 20;
            sentence = realloc(sentence, size * sizeof(char));
        }
        sentence[n] = symbol;
        n++;
    }
    sentence[n] = '\0';
    return sentence;
}