// main.c
#include <stdio.h>
#include "myheader.h"

int main() {
    greet(); 
    printf("Global variable: %d\n", globalVar);
    return 0;
}
