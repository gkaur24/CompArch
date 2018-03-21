//
//  calc.h
//  
//
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stuff{
    
    int first;
    int second;
    int result;
    char operation;
    char finalstate;
    char firsttype;
    char secondtype;
    int sign1;
    int sign2;
};

typedef struct stuff Arguments;

Arguments* parser(char** given );

int add (int first, int second,int sign1, int sign2);
int subtract(int first, int second,int sign1, int sign2);
int multiply(int first, int second,int sign1, int sign2);
int convertToInt(char* en, char type);
int convertFinalForm(int n, char form);
