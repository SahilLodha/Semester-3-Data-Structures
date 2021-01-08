#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void valueInsert(int* , int);
void valueSort(int*, int);
void valuePrint(int*, int);

int main(){
    int  size;
    char checker;
    int *ptr;

    printf("Enter m for malloc\n"
           "Enter c for calloc\n"
           "value: ");
    fflush(stdin);
    scanf("%c", &checker);

    // No of inputs from user
    printf("Enter the no of the Elements in the list: ");
    scanf("%d", &size);


    // Creating an integer array of the entered size...
    if (tolower(checker) == 'm'){
        ptr = (int*)malloc(size* sizeof(int));
        printf("Malloc Successful..\n\n");
    } else if (tolower(checker) == 'c'){
        ptr = (int*)calloc(size, sizeof(int));
        printf("Calloc Successful..\n\n");
    }else{
        printf("No such operation can be done..");
        exit(3);
    }

    // Inserting values into array...
    valueInsert(ptr, size);

    // Printing Initial List...
    printf("Initial List: ");
    valuePrint(ptr, size);

    // Sorting provided list...
    valueSort(ptr, size);

    // Printing the sorted list...
    printf("Final(Sorted) List: ");
    valuePrint(ptr, size);

    // For the next list(if present)...
    // Asking user if next list is present or not...
    printf("Do you have another list(y/n)?");
    fflush(stdin);
    scanf("%c", &checker);

    if(checker == 'y'){
        do{
            // If list is present then take new size of the list...
            printf("Enter the new size of array: ");
            scanf("%d", &size);

            // Using the same pointer to create another list of different size...
            ptr = (int*)realloc(ptr, size* sizeof(int));
            printf("Realloc Successful...\n\n");
            // Repeating the insertion, sorting and printing process for the newly created list...
            valueInsert(ptr, size);
            printf("Initial List: ");
            valuePrint(ptr, size);
            valueSort(ptr, size);
            printf("Final(Sorted) List: ");
            valuePrint(ptr, size);

            // Asking for the next list if present(for looping)....
            printf("Do you have another list(y/n)?");
            fflush(stdin);
            scanf("%c", &checker);
        }while(tolower(checker) == 'y');

        // To display the user its mistake if it enters wrong input..
        if(tolower(checker) == 'n'){
            printf("Thank you for your patience");
        }else{
            printf("y and n were the characters to be entered\nWrong Entry Error!!\nProgram Crashed...");
        }
    }

    // Deleting all the space allocated to the pointer...
    free(ptr);
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
    char decider;
    int i,j, temp;
    printf("For ascending order press a\nFor descending press b \nValue: ");
    fflush(stdin);
    scanf("%c", &decider);
    for(i = 0;  i<n ; i++) {
        for (j = i+1; j <n ; j++){
            if(tolower(decider) == 'a'?*(num+i) > *(num+j):*(num+i) < *(num+j) ){
                temp = *(num+i);
                *(num+i) = *(num+j);
                *(num+j) = temp;
            }
        }
    }
}