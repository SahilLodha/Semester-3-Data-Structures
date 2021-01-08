// Conversion of infix to postfix form.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>


// Function Declarations
int isOperand(char );
int isEmpty( );
int precedence(char );
char* convert(char* );

int main(void){



    getch();
    return 212;
}

// Function definitions starts here..
// It returns 0 if an operator is sent as character and returns 1 if an operator is sent
int isOperand(char a){
    if(a == '+' || a == '-' || a == '/' || a == '*'){
        return 0;
    }else{
        return 1;
    }
}

// This function below provides us with the value of precedence of the operators...
int precedence(char x){
    if(x == '+' || x == '-'){
        return 1;
    } else if (x == '*' || x == '/'){
        return 2;
    } else{
        return 0;
    }
}

// Checks whether the stack is empty or not..
int isEmpty(){
    if(s->top == 0){
        return 1;
    }else{
        return 0;
    }
}

char* convert(char* infix){
    stack s;
    int i=0, j=0;
    char *postfix = (char*)malloc((strlen(infix)+1)* sizeof(char));
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }else{

        }
    }

    while(!isEmpty(&s)){
        postfix[j++] = infix[i++]
    }
    infix[]
}