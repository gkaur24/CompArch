// calc.c

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"


Arguments* parser(char** given ){
    
    Arguments *Curr = malloc(sizeof(Arguments));
    //Set the Sign of both arguments to positive
    Curr -> sign1=0;
    Curr -> sign2=0;
    //where argv[1] : the operation
    Curr -> operation = given[1][0];
   
    if(given[1][0] != '+' && given[1][0] != '-' && given[1][0] != 'x' && given[1][0] != '/' ){
       
        fprintf(stderr,"ERROR! Incorrect Opertation type\n"); //error
        exit(0);
    }
    
    Curr -> firsttype = given[2][0];  //where argv[2][0] is the first given and type
    
    if(given[2][0]== '-'){
       
        Curr->firsttype = given[2][1];
        Curr->sign1 = 1;
       
        if(given[2][1] != 'b'&& given[2][1] != 'B'&& given[2][1] != 'd' && given[2][1] != 'D'&& given[2][1] != 'o'&& given[2][1] != 'O'&& given[2][1] != 'x'&& given[2][1] != 'X'){
            
            fprintf(stderr,"ERROR! Incorrect Characther type\n");
            exit(0);
        }
        
    }
    else if(Curr->sign1 != 1 && given[2][0] != 'b'&& given[2][0] != 'B'&& given[2][0] != 'd' && given[2][0] != 'D'&& given[2][0] != 'o'&& given[2][0] != 'O'&& given[2][0] != 'x'&& given[2][0] != 'X'){
     
        fprintf(stderr,"ERROR! Incorrect Charcther type\n");
        exit(0);
    }
    
    //where argv[2]: All the of the first argument:
    char* temp = given[2];
    temp = temp+1;
   
    if(Curr->sign1 == 1){
        temp = temp+1;}
    //printf("temp %s\n ", temp);
    Curr -> first = convertToInt(temp, Curr->firsttype);
    
    //where argv[3][0]:the second given and type
    Curr -> secondtype = given[3][0];
   
    if(given[3][0]== '-'){
        
        Curr -> secondtype = given[3][1];
        Curr -> sign2 = 1;
        
        if(given[3][1] != 'b'&& given[3][1] != 'B'&& given[3][1] != 'd' && given[3][1] != 'D'&& given[3][1] != 'o'&& given[3][1] != 'O'&& given[3][1] != 'x'&& given[3][1] != 'X'){ fprintf(stderr,"ERROR! Incorrect Character type\n ");
            exit(0);}
        
    }
    else if (Curr->sign2 != 1 && given[3][0] != 'b'&& given[3][0] != 'B'&& given[3][0] != 'd' && given[3][0] != 'D'&& given[3][0] != 'o'&& given[3][0] != 'O'&& given[3][0] != 'x'&& given[3][0] != 'X'){
        
        fprintf(stderr,"ERROR!!22 You did not enter the Correct Character type\n ");
        exit(0);}
    
    //where argv[3]: All of the second argument
    char* temp2 = given[3];
    temp2 = temp2+1;
   
    if(Curr->sign2 == 1){
        temp2 = temp2+1;
    }
    //printf("temp %s\n ", temp2);
    Curr -> second = convertToInt(temp2, Curr->secondtype);
    
    //where argv[4]:the final operant
    Curr -> finalstate= given[4][0];
    
    if(given[4][0] != 'b' && given[4][0] != 'B' && given[4][0]!='x' && given[4][0]!='X' && given[4][0] != 'o'&& given[4][0] != 'O' && given[4][0]!= 'd' && given[4][0]!='D'){
        fprintf(stderr,"ERROR!! Incorrect Final form type\n");
        exit(0);
    }
    
    return Curr;
}

int convertToInt(char* en, char type){
    
    //When you are given a Decimal
    if(type == 'd' || type =='D'){
       
        int counter = strlen(en)-1;
        int power = 1;
        int output = 0;
        while(counter != -1){
            
            if(en[counter]=='1'){
                output = output + (1*power);
                power = power *10;
                counter--;
            }
            else if( en[counter] == '2'){
                output = output + (2*power);
                power = power*10;
                counter--;
            }
            
            else if( en[counter] == '3'){
                output = output + (3*power);
                power = power*10;
                counter--;
            }
            
            else if( en[counter] == '4'){
                output = output + (4*power);
                power = power*10;
                counter--;
            }
            
            else if( en[counter] == '5'){
                output = output + (5*power);
                power = power*10;
                counter--;
            }
            
            else if( en[counter] == '6'){
                output = output + (6*power);
                power = power*10;
                counter--;
            }
            
            else if( en[counter] == '7'){
                output = output + (7*power);
                power = power*10;
                counter--;
            }
            else if( en[counter] == '8'){
                output = output + (8*power);
                power = power*10;
                counter--;
            }
            
            else if( en[counter] == '9'){
                output = output + (9*power);
                power = power*10;
                counter--;
            }
            else if( en[counter] == '0'){
                output = output + (0*power);
                power = power*10;
                counter--;
            }
            else{
                printf("ERROR!! The Argument you entered is flawed, The Character: %c - IS NOT A DECIMAL\n", en[counter]);
                exit(0);
            }
        }
        return output;
    }
    
    
    //When you are given a Binary
    else if( type == 'b' || type == 'B'){
        
        int counter = strlen(en)-1;
        int power=1;
        int output=0;
       
        while(counter !=-1){
           
            if(en[counter] == '1'){
                output = output + power;
                power=power*2;
                counter--;
            }
            
            else if (en[counter] == '0'){
               
                power= power*2;
                counter--;
                continue;
            }
            
            else{
                fprintf(stderr,"ERROR! You entered a non-binary number in a binary string");
                exit(0);
            }
            
            
        }
        return output;
        //printf("Should not be here %d \n", output);
    }
    
    
    //When you are given a HexaDecimal
    else if( type == 'x' || type == 'X'){
        
        int counter = strlen(en)-1;
        int power =1;
        int output =0;
       
        while(counter != -1){
            
            if( en[counter] == '0'){
              
                output = output + (0*power);
                power = power*16;
                counter--;
            }
            
            else if( en[counter] == '1'){
                
                output = output + (1*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == '2'){
                
                output = output + (2*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == '3'){
                
                output = output + (3*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == '4'){
                
                output = output + (4*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == '5'){
                
                output = output + (5*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == '6'){
               
                output = output + (6*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == '7'){
                
                output = output + (7*power);
                power = power*16;
                counter--;
            }
            else  if( en[counter] == '8'){
                
                output = output + (8*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == '9'){
                
                output = output + (9*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == 'a'|| en[counter] == 'A'){
               
                output = output + (10*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == 'b'|| en[counter] == 'B'){
              
                output = output + (11*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == 'c'|| en[counter] == 'C'){
              
                output = output + (12*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == 'd'|| en[counter] == 'D'){
                
                output = output + (13*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == 'e'|| en[counter] == 'E'){
                
                output = output + (14*power);
                power = power*16;
                counter--;
            }
            
            else  if( en[counter] == 'f'|| en[counter] == 'F'){
                
                output = output + (15*power);
                power = power*16;
                counter--;
            }
            else{
                
                fprintf(stderr,"ERROR! You entered a non-HEX number in a HEX string");
                exit(0);
                
            }
        }
        return output;
    }
    
    //When you are given an Octal
    else if(type == 'o' || type == 'O'){
       
        int counter = strlen(en)-1;
        int power =1;
        int output =0;
       
        while(counter != -1){
           
            if(en[counter]=='1'){
                output = output + (1*power);
                power = power *8;
                counter--;
            }
            else if( en[counter] == '2'){
                output = output + (2*power);
                power = power*8;
                counter--;
            }
            
            else if( en[counter] == '3'){
                output = output + (3*power);
                power = power*8;
                counter--;
            }
            
            else if( en[counter] == '4'){
                output = output + (4*power);
                power = power*8;
                counter--;
            }
            
            else if( en[counter] == '5'){
                output = output + (5*power);
                power = power*8;
                counter--;
            }
            
            else if( en[counter] == '6'){
                output = output + (6*power);
                power = power*8;
                counter--;
            }
            
            else if( en[counter] == '7'){
                output = output + (7*power);
                power = power*8;
                counter--;
            }
            else{
                fprintf(stderr,"ERROR! You entered a non-Oct number in a Oct string");
                exit(0);
            }
        }
        return output;
        
    }
    return 0;
}
// add function
int add (int first, int second, int sign1, int sign2){
   
    int temp;
   
    if(sign1 == 1){
    
        first = first *-1;
    }
    
    if(sign2 ==1){
    
        second = second * -1;
    }
    //printf("first %d and second %d", first, second);
    temp = first + second;
    return temp;
}

//subtract function
int subtract(int first, int second, int sign1, int sign2){
    int temp;
   
    if(sign1 == 1){
        first =first * -1;
    }
    if(sign2 ==1){
        second =second *-1;
    }
    //printf("first %d and second %d", first, second);
    temp = first- second;
    return temp;
}

// multiply function
int multiply(int first, int second,int sign1, int sign2){
    int temp;
    if(sign1 == 1){
        first =first * (-1);
    }
    if(sign2 ==1){
        second =second *-1;
    }
    //printf("first %d and second %d", first, second);
    temp = first * second;
    return temp;
}

// This function takes the number and converts it to the required output base
int convertFinalForm(int n, char form){
   
    //Convert from int to Binary
    if( form == 'b' || form == 'B'){ 
       
        int remainder;
        int binary = 0, i = 1;
        
        while(n != 0) {
            
            remainder = n%2;
            n = n/2;
            binary = binary + (remainder*i);
            i = i*10;
        }
        return binary;
    }
    
    
    //Convert from int to Hexadecimal
    else if( form == 'x' || form == 'X'){
       
        long int deciNum,quotient;
        int i=1,j,temp;
        char hexadecimalNumber[100];
        
        deciNum = n;
        
        quotient = deciNum;
        
        while(quotient!=0){
           
            temp = quotient % 16;
            
            //To convert integer into character
            if( temp < 10){
                temp =temp + 48;
            }
            else{
                temp = temp + 55;
            }
            
            hexadecimalNumber[i++]= temp;
            quotient = quotient / 16;
        }
        
        printf(" ");
        
        for(j = i -1 ;j> 0;j--){
            printf("%c",hexadecimalNumber[j]);
        }
        
        printf("\n");
        exit(0);
        
    }
    //Convert from int to Octal
    else if( form == 'o' || form == 'O'){
        int result=0;
        int digitPos=1;
       
        while (n) {
            result += (n%8)*digitPos;
            n /= 8;
            digitPos *= 10;
        }
        return result;
    }
    //Convert from int to Decimal
    else if( form == 'd' || form == 'D'){
        return n;
    }
    //Something is wrong, final conversion not found
    else{
        printf("ERROR! No final form found");
    }
    return 1;
}

int main (int argc , char** argv){
    
    if( argc < 4 ){
       
        fprintf(stderr,"ERROR! You did not enter the correct amount of arguments\n");
        exit(0);
    }
    
    Arguments *Arg;
    Arg = parser(argv);
    
    
    if(Arg -> operation == '+' ){
        Arg -> result = add(Arg->first, Arg->second, Arg->sign1, Arg->sign2);
        printf("%c%d \n", Arg -> finalstate,convertFinalForm(Arg->result, Arg -> finalstate));
        return 0 ;
    }
    if(Arg -> operation == '-' ){
        Arg -> result = subtract(Arg->first, Arg->second, Arg->sign1, Arg->sign2);
        printf("%c%d \n", Arg -> finalstate,convertFinalForm(Arg->result, Arg -> finalstate));
        return 0 ;
    } 
    if(Arg -> operation == '*' ){
        Arg -> result = multiply(Arg->first, Arg->second, Arg->sign1, Arg->sign2);
        printf("%c%d \n", Arg -> finalstate,convertFinalForm(Arg->result, Arg -> finalstate));
        exit(0); 
    }
    
    return 0 ;
    
}
