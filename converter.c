#include "converter.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char* converter(const char* str){
    char* buf;
    int len;
    buf = calloc(strlen(str) + 1, sizeof(char));
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