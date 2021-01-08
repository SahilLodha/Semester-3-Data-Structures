#include <stdio.h>

void hanoiFun(int ,char ,char ,char);

int main(){
    int no_disk;

    printf("Enter the number of disk: ");
    scanf("%d", &no_disk);


    printf("\nSolution Sequence:");
    hanoiFun(no_disk, 'A', 'B', 'C');
    return  0;
}

void hanoiFun(int n, char from, char to, char aux){
    if(n==1){
        printf("\nMove disk 1 from rod %c to rod %c\n", from, to);
        return;
    }

    hanoiFun(n-1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c", n, from, to);
    hanoiFun(n-1, aux, to, from);
}


