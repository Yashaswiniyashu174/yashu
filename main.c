main.c

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    printMessage("Hello from hello.c with a parameter!");
    return 0;
}



hello.c


#include "hello.h"
#include<stdio.h>

void printMessage(const char* message){
    printf("%s\n",message);
}



hello.h

#ifndef HELLO_H
#define HELLO_H

void printMessage(const char* message);

#endif

