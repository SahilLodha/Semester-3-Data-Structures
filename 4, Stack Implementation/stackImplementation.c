#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TOP -1

typedef struct{
    int *s;
    int size;
    int top;
}stack;

int isEmpty(stack);
int isFull(stack);
// Functions below change the parameters of the stack structure...
int pop(stack*);
void push(stack*);

int main() {
    stack stack;
    int temp, control = 1;
    char choice;

    printf("Enter the size of stack to be created? ");
    scanf("%d", &(stack.size));
//    stack.size = temp;

    // Initial top of stack
    stack.top = TOP;
    stack.s = (int*)calloc(stack.size ,sizeof(int));

    do{
        printf("Enter 2 POP operation\n"
               "Enter 1 PUSH operation\n"
               "Enter 3 to exit:");
        scanf("%d", &temp);

        if(temp == 1){
            push(&stack);
        }else if(temp == 2){
            pop(&stack);
        }else{
            break;
        }
    }while(temp != 3);
    free(stack.s);
    getch();
}

int isEmpty(stack s){
    if(s.top == -1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(stack s){
    if(s.top == (s.size-1)){
        return 1;
    } else{
        return 0;
    }
}

void push(stack* st){
    int temp;
    if(isFull(*st)){
        printf("The stack is full\nCannot insert values...");
    }else{
        (st->top)++;
        printf("What is the value to be inserted: ");
        scanf("%d", &temp);
        st->s[st->top] = temp;
    }
}

int pop(stack* st){
    if(isEmpty(*st)){
        printf("The stack is empty\nCannot POP value...\n");
    }else{
        printf("The POP result: %d\n", st->s[st->top]);
        st->s[st->top] = 0;
        st->top--;
        printf("The new stack top: %d\n", st->top);
    }
}