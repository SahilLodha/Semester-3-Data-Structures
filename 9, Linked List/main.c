#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_begin(int);
void insert_end(int);
void traverse();
void delete_begin();
void delete_end();

int count = 0;
struct node *start = NULL;

int main() {
    int option, element;

    for(;;){
        printf("Press 1: To insert node at the very beginning\n"
               "Press 2: To insert node at the very end\n"
               "Press 3: To delete node at the very beginning\n"
               "Press 4: To delete node at the very end\n"
               "Press 5: To traverse through the linked list\n"
               "Press 6: Exit Program\n"
               "Option: ");

        scanf("%d", &option);

        if(option == 1){
            printf("Enter value to add: ");
            scanf("%d", &element);
            insert_begin(element);
        }else if(option==2){
            printf("Enter value to add: ");
            scanf("%d", &element);
            insert_end(element);
        }else if(option==3){
            delete_begin();
        }else if(option==4){
            delete_end();
        }else if(option==5){
            traverse();
        }else if(option == 6){
            break;
        }else{
            printf("Please enter a valid Input.\n");
        }
    }
}

void traverse(){
    struct node *t;

    t = start;

    if (t == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    printf("\n<---------- Details Start Here ---------->\n");
    printf("There are %d elements in linked list.\n", count);
    int i = 1;

    while (t->next != NULL) {
        printf("Element in position %d: %d\n", i, t->data);
        t = t->next;
        i++;
    }
    printf("Last Element is %d.\n", t->data);
    printf("<----------- Details End Here ----------->\n\n");
}

void insert_begin(int value){
    struct node *t;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = value;
    count++;

    if (start == NULL){
        start = t;
        start->next = NULL;
        return;
    }

    t->next = start;
    start = t;
}

void insert_end(int value){
    struct node *t, *temp;

    t = (struct node*)malloc(sizeof(struct node));
    t->data = value;
    count++;

    if(start == NULL){
        start = t;
        start->next = NULL;
        return;
    }
    temp = start;

    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = t;
    t->next = NULL;
}

void delete_begin(){
    struct node *t;
    int n;

    if (start == NULL) {
        printf("Linked list is empty.\n");
        return ;
    }

    n = start->data;
    t = start->next;
    free(start);
    start = t;
    count--;

    printf("%d deleted from the beginning successfully.\n", n);
}

void delete_end() {
    struct node *t, *u;
    int n;
    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    count--;

    if (start->next == NULL) {
        n = start->data;
        free(start);
        start = NULL;
        printf("%d deleted from end successfully.\n", n);
        return;
    }
    t = start;

    while (t->next != NULL) {
        u = t;
        t = t->next;
    }
    n = t->data;

    u->next = NULL;
    free(t);
    printf("%d deleted from end successfully.\n", n);
}
