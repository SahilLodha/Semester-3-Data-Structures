// This program demonstrates the use of Malloc.
#include <stdio.h>
#include <stdlib.h>
void valueInsert(int*, int);
void valuePrint(int*, int);
void valueSort(int*, int);

int main() {
    int* num;
    int n;

    // Taking the no of entries from the user
    printf("How many numbers are there: ");
    scanf("%d", &n);

    // Using Malloc To create array(int) dynamically
    num = (int*)calloc(n, sizeof(int));

    // Checking if the calloc allocated memory or not..
    if(num == NULL){
        printf("The memory has not been allocated...\nRerun with a different entry(positive integer)");
        exit(1);
    }else{
        printf("Memory allocation successful..\n");
    }

    // Checking for initial values....
    printf("Checking the values before insertion of values from the user..");
    valuePrint(num, n);

    // Inserting Values...
    valueInsert(num, n);

    // Obtaining inserted Values....
    printf("Initial List: ");
    valuePrint(num, n);

    // Sorting ...
    valueSort(num, n);

    // Checking Final List....
    printf("\nFinal List: ");
    valuePrint(num, n);

    // Deallocate memory
    free(num)
}

void valueInsert(int* num, int n){
    int i;
    for(i = 0; i<n; i++){
        printf("Enter the entry %d: ", i+1);
        scanf("%d", (num+i));
    }
}

void valuePrint(int* num, int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d\t", *(num+i));
    }
    printf("\n");
}

void valueSort(int* num, int n){
    int i,j, temp;
    for (i = 0;  i<n ; i++) {
        for (j = i+1; j <n ; j++){
            if(*(num+i) > *(num+j)){
                temp = *(num+i);
                *(num+i) = *(num+j);
                *(num+j) = temp;
            }
        }
    }
}