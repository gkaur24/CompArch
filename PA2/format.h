//
//  format.h
//  
//
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct format{
   
    char* binary;
    int decimal;
    char* floats;
    char sign;
};

typedef struct  format count;

int binarytoint(char*en);
int twoscompliment(count* x);


