#include "structText.h"
#include "printer.h"
#include <stdio.h>


void printer(struct Text* text){
    for (int i = 0; i < text -> number; i++) {
        printf("%s", text -> arr[i]);
    }
}
