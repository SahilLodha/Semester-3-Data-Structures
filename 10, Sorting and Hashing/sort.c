#include <stdio.h>
#include <stdlib.h>

// Main Sorting Function
void bubble_sort(int*, int);
void insertion_sort(int*, int);
void selection_sort(int*, int);
void shell_sort(int*, int);
void quick_sort(int*, int, int);
int merge_sort(int*, int);

// Supporting Functions
void swap(int*, int*);
void array_print(const int*, int);
void array_create(int*, int);
int partition(int*, int, int);

int main() {
    int *ary;
    int size, option;


    printf("<-------- Menu Start -------->\n"
           "Press 1: Bubble Sort\n"
           "Press 2: Insertion Sort\n"
           "Press 3: Quick Sort\n"
           "Press 4: Merge Sort\n"
           "Press 5: Selection Sort\n"
           "Press 6: Shell Sort\n"
           "Press 7: Heap Sort"
           "Press 8: Exit\n"
           "<-------- Menu Ends -------->\n");


    do {
        printf("Enter your Option: ");
        scanf("%d", &option);

        if(option<8){
            printf("Enter the size of the array to be sorted: ");
            scanf("%d", &size);
            ary = (int*)calloc(size, sizeof(int));
            array_create(ary, size);

            printf("The initial array:\n");
            array_print(ary, size);
        }

        if (option==1){
            bubble_sort(ary, size);
            printf("Final Sorted Array: \n");
            array_print(ary, size);
        }else if(option==2){
            insertion_sort(ary, size);
            printf("Final Sorted Array: \n");
            array_print(ary, size);
        }else if(option==3){
            quick_sort(ary, 0,size);
            printf("Final Sorted Array: \n");
            array_print(ary, size);
        }else if(option==4){
            merge_sort(ary, size);
            printf("Final Sorted Array: \n");
            array_print(ary, size);
        }else if(option==5){
            selection_sort(ary, size);
            printf("Final Sorted Array: \n");
            array_print(ary, size);
        }else if(option==6){
            shell_sort(ary, size);
            printf("Final Sorted Array: \n");
            array_print(ary, size);
        }else if(option==7){

        }else if (option==8){
            printf("\n<------------ Thank You ------------>\n");
        }else{
            printf("Please enter a valid Input\n");
        }
    }while(option!=8);

}

void array_create(int *arr, int len){
    for(int i=0; i< len; i++){
        printf("Enter value for element %d", i+1);
        scanf("%d", (arr+i));
    }
}

void array_print(const int *a, int len_a){
    for(int i = 0; i < len_a-1; i++){
        printf("%d | ", *(a+i));
    }
    printf("%d\n", *(a+len_a-1));
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* list, int start, int end){
    int pivot = list[start];
    int i = start, j = end;

    do{
        do{i++;}while (list[i]<=pivot);
        do{j--;}while (list[j]>pivot);

        if(i<j)swap(list+i, list+j);
    }while (i<j);

    swap(list+j, list+start);
    return j;
}

void bubble_sort(int *arr, int len){
    int no_of_swaps = 0, no_of_iterations = 0;
    printf("\nRunning Simulations For Bubble Sort:\n");

    for (int i = 0; i < len-1; i++){
        for (int j = 0; j < len - i - 1; j++){
            no_of_iterations += 1;
            if (arr[j] > arr[j+1]){
                no_of_swaps += 1;
                swap((arr+j), (arr+j+1));
            }
            array_print(arr, len);
        }
    }
    printf("The number of Swaps: %d\n", no_of_swaps);
    printf("The number of Iteration: %d\n", no_of_iterations);
}

void insertion_sort(int *arr, int len){
    int no_of_iterations = 0;

    for(int i = 1; i < len; i++){
        int key = arr[i];
        int j = i - 1;

        while (key < arr[j] && j >= 0){
            no_of_iterations++;
            arr[j+1] = arr[j];
            j -= 1;

        }
        arr[j+1] = key;
        array_print(arr, len);
    }

    printf("The no of iterations are %d\n", no_of_iterations);
}

void quick_sort(int *arr, int start, int end){
    int partition_index;

    if(start<end){
        partition_index = partition(arr, start, end);
        quick_sort(arr, start, partition_index);
        quick_sort(arr, partition_index+1, end);
    }
}

int merge_sort(int *arr, int len){

}

void shell_sort(int *list, int len){
    int gap,i,j,temp, no_of_iteration=0;

    printf("Simulating Shell Sorting: \n");
    for(gap=len/2;gap>=1;gap/=2){
        for(i=gap;i<len;i++){
            temp=list[i];
            j=i-gap;

            while(j>=0 && list[j]>temp){
                no_of_iteration++;
                list[j+gap]=list[j];
                j=j-gap;
            }

            list[j+gap]=temp;
            array_print(list, len);
        }
    }

    printf("The no. of required Iteration are %d", no_of_iteration);
}

void heap_sort(){

}

void selection_sort(int *list, int len){
    int no_of_swaps = 0, no_of_iteration=0;

    printf("Running simulation for selection sort: \n");
    for (int i=0; i<len-1; i++){
        for(int j=i+1; j<len; j++){
            no_of_iteration++;
            if(list[j] < list[i]){
                no_of_swaps++;
                swap((list+j), (list+i));
            }
            array_print(list, len);
        }
    }

    printf("The no of Iterations are: %d\n", no_of_iteration);
    printf("The no. of swaps are: %d\n", no_of_swaps);
}