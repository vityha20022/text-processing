


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Text{
    char** arr;
    int n;
    int size;
};
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

char* converter(const char* str){
    char* buf;
    buf = malloc(strlen(str));
    int len;
    buf = strcpy(buf, str);
    len = strlen(buf);
    if (buf[0] == ' '){
        for(int i = 0; i < len; i++){
            buf[i] = buf[i + 1];
        }
    }
    for (int i = 0; i < len; i++){
        buf[i] = (char)tolower(buf[i]);
    }

    return buf;
}
struct Text* delete(struct Text* text){
    int i = 0;
    char* first;
    char* last;
    while (i < text -> n){
        first = converter(text -> arr[i]);
        int j = i + 1;
        while(j < text -> n + 1){
            last = converter(text -> arr[j]);
            if(!strcmp(first, last)){
                free(text -> arr[j]);
                for (int k = j; k < text -> n; k++){
                    text -> arr[k] = text -> arr[k + 1];
                }
                text -> n--;
                free(last);
            }
            else{
                free(last);
                j++;
            }

        }
        free(first);
        i++;
    }
    return text;
}





int main() {
    struct Text text;
    struct Text *pointer;
    pointer = &text;
    text.size = 20;
    text.n = 0;
    char **arr;
    arr = malloc(text.size * sizeof(char *));
    text.arr = arr;
    while (1) {
        char *sentence = readSentence();
        if (text.n == text.size - 1) {
            text.size += 20;
            // добавить проверку реалока
            text.arr = realloc(text.arr, sizeof(char *) * text.size);
        }
        if (strchr(sentence, '\n')) {
            break;
        }
        text.arr[text.n] = sentence;
        text.n++;

    }
    text.n--;

    pointer = delete(pointer);


    for (int i = 0; i < text.n + 1; i++) {
        printf("%s", pointer->arr[i]);
    }


}

int function() {
    return 0;
}
