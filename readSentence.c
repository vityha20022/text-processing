
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readSentence(){
    int size = 20;
    int n = 0;
    char* sent = malloc(size * sizeof(char));
    char symbol;
    symbol = getchar();
    sent[n] = symbol;
    n++;
    while(!strchr(".\n", symbol)) {
        symbol = getchar();
        if (n == size - 1) {
            size += 20;
            sent = realloc(sent, size * sizeof(char));
        }
        sent[n] = symbol;
        n++;
    }
    sent[n] = '\0';
}