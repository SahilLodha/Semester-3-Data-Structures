#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int*, int);
void linear_search(const int*, int, int);
void binary_search(const int*, int, int, int);
void print_array(const int*, int);
void array_create(int*, int);
void swap(int*, int*);

int main() {
    int size, option, value;
    int *arr;

    printf("<--------- Menu Start --------->\n");
    printf("Press 0: Reinitialize array\nPress 1: Linear Search\nPress 2: Binary Search\nPress 3: Exit");
    printf("\n<---------- Menu End ---------->\n");

    printf("Enter a option from the Menu: ");
    scanf("%d", &option);

    if (option<3 && option>=0){
        printf("Enter the size of array to be created: ");
        scanf("%d", &size);
        arr = (int*)calloc(size, sizeof(int));

        array_create(arr, size);
        print_array(arr, size);
    }

    while(option!=3){
        if (option==1){
            printf("Enter the value to search for: ");
            scanf("%d", &value);
            linear_search(arr, size, value);
        }else if(option==2){
            printf("Enter the value to search for: ");
            scanf("%d", &value);
            bubble_sort(arr, size);
            binary_search(arr, size-1, 0, value);
        }else if(option==3){
            printf("<--------- Thank You --------->");
        }else if(option==0){
            printf("Enter the size of array to be created: ");
            scanf("%d", &size);
            arr = (int*)calloc(size, sizeof(int));
            array_create(arr, size);
            print_array(arr, size);
        }else{
            printf("Enter a valid option\n");
        }

        printf("Enter a option from the Menu: ");
        scanf("%d", &option);
    }
}


void array_create(int *arr, int len){
    for (int i=0; i<len; i++){
        printf("Enter value for place %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void linear_search(const int *a, int len, int search_value){
    for(int i=0; i<len; i++){
        if(a[i] == search_value){
            printf("The search value found at position %d of the array indexed from 0.\n", i);
        }
    }
}

void binary_search(const int *a, int end, int start, int search_value){
    int mid = (int)((end-start)/2);

    if(a[end]<search_value){
        printf("Element not in array\n");
        return;
    }else if(a[end] == search_value){
        printf("Found in location %d of array.\n", end);
        return;
    }else if(a[start] == search_value){
        printf("Found in location %d of array.\n", start);
        return;
    }

    if (a[mid] == search_value){
        printf("Element Found at index %d of array.\n", mid);
        return;
    }else if(end-1 == start || end == start){
        printf("Element not found\n");
        return;
    }else{
        if(a[mid] < search_value){
            binary_search(a, end, mid, search_value);
        }else{
            binary_search(a, mid, 0, search_value);
        }
    }
}

void bubble_sort(int *list, int len){
    for (int i = 0; i < len-1; i++){
        for (int j = 0; j < len - i - 1; j++){
            if (list[j] > list[j+1]){
                swap((list+j), (list+j+1));
            }
        }
    }
}

void swap(int *a,int *b ){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(const int *a, int len){
    for (int i=0; i<len-1; i++){
        printf("%d | ", a[i]);
    }

    printf("%d\n", a[len-1]);
}