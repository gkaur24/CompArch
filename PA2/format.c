//
//  format.c
//  
//
//  .
//
//

#include "format.h"

count *mCreator(char* x){
   
    count *m = malloc(sizeof(count));
    m -> binary = malloc(sizeof(x));
    m -> floats = malloc(sizeof(x));
    return m;
}

int twoscompliment(count* x){
    
    int strlength;
    int value;                          // value is the decimal number
    strlength = strlen(x -> binary)-1;
    
    if(x -> binary[0] == '1'){
       
        x->sign='-';
    }
    else if(x -> binary[0] == '0'){
        
        x -> sign='+';
    }
    
    for( strlength= strlen(x -> binary)-1; strlength > -1; strlength--){
        
        if(x -> binary[strlength] == '1'){
            
            x -> binary[strlength] = '0';
        }
        
        else if (x -> binary[strlength] == '0'){
           
            x -> binary[strlength] = '1';}
        
        else{
          
            fprintf(stderr,"Error, you entered a non-BINARY number\n");
            exit(0);
        }
    }
    
    value = binarytoint(x -> binary);
    value = value +1;
   
    return value;
    
}

int binarytoint(char*en){       // convert binary to int
    
    
    int count = strlen(en)-1;
    int power=1;
    int outcome=0;
   
    while(count !=-1){
        
        if(en[count] == '1'){
            outcome = outcome + power;
            power = power*2;
            count--;
        }
        
        else{
            power = power*2;
            count--;
            continue;
        }
    }
    
    return outcome;
}

int main(int argc, char** argv){
   
    char* type;
   
    if (argc <3 ){
        
        fprintf(stderr,"Error, incorrect amount of arguments");
        exit(0);
    }
    
    count *m;
    m =mCreator(argv[1]);
    m->binary = argv[1];
    type = argv[2];
   
    if(type[0] == 'i' || type[0] == 'I'){
        m -> decimal = twoscompliment(m);
        m -> decimal= m -> decimal * -1;
        printf("%d \n",  m -> decimal);
    }
    
    else if( type[0] =='f' || type[0] =='F'){  //??????
        
    }
    return 0;
}
