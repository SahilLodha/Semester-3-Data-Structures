#include <stdio.h>

int multiplier(int );
static int fact = 1;

int main() {
    int number, option;

    do{
        printf("Enter a number whose factorial is to be found: ");
        scanf("%d", &number);
        printf("The factorial is %d.\n", multiplier(number));

        // Reinitialize fact for next iteration.
        fact = 1;

        printf("\n<--------- ** END OF ITERATION ** --------->\n");
        printf("Enter 1 to exit. Press other integer to continue: ");
        scanf("%d", &option);
    }while(option != 1);
}

int multiplier(int num){
    if(num==0){
        return 1;
    }

    if(num != 1){
        fact =  num*multiplier(num-1);
    }else{
        return fact;
    }
}