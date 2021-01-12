#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void insert_begin(int);
void insert_end(int);
void traverse();
void delete_begin();
void delete_end();
void insert_after_k(int, int);
void delete_k(int);

int count = 0;
struct Node *start = NULL;

int main() {
    int option, element, key;

    printf("<-------------- Menu Starts Here -------------->\n"
           "Press 1: To insert node at the very beginning\n"
           "Press 2: To insert node at the very end\n"
           "Press 3: To delete node at the very beginning\n"
           "Press 4: To delete node at the very end\n"
           "Press 5: To insert node after a value\n"
           "Press 6: To delete node with value\n"
           "Press 7: To traverse through the linked list\n"
           "Press 8: Exit Program\n"
           "<--------------- Menu Ends Here --------------->\n");

    for(;;){
        printf("Select Option: ");
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
            printf("Enter the value to add: ");
            scanf("%d", &element);
            printf("Enter a element after which insertion is to be performed: ");
            scanf("%d", &key);
            insert_after_k(key, element);
        }else if(option==6){
            printf("Enter the data which is to be removed from the linked list: ");
            scanf("%d", &key);

            delete_k(key);
        }else if(option==7){
            traverse();
        }else if(option == 8){
            break;
        }else{
            printf("Please enter a valid Input.\n");
        }
    }
}

void traverse(){
    struct Node *t;
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
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
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
    struct Node *t, *temp;

    t = (struct Node*)malloc(sizeof(struct Node));
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
    struct Node *t;
    int n;

    if (start == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    n = start->data;
    t = start->next;
    free(start);
    start = t;
    count--;

    printf("%d deleted from the beginning successfully.\n", n);
}

void delete_end() {
    struct Node *t, *u;
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

void insert_after_k(int key, int value){
    struct Node *temp, *insert_node;
    temp = start;
    insert_node = (struct Node*)malloc(sizeof(struct Node));
    insert_node->data = value;

    if (start==NULL){
        printf("This is an empty Linked List. \nInsertion Failed (Node not found)");
        return;
    }

    while (temp->data != key && temp!=NULL){
        printf("Here %d\n", temp->data);
        temp = temp->next;
    }


    if (temp==NULL){
        printf("Cannot find any Node with value %d", key);
        return;
    }

    insert_node->next = temp->next;
    temp->next = insert_node;
    count ++;
}

void delete_k(int key){
    struct Node *delete_node, *previous_node=NULL;
    delete_node = start;
    printf("Reached Here\n");

    while (delete_node!=NULL && delete_node->data!=key){
        printf("While loop!\n");
         previous_node = delete_node;
        delete_node = delete_node->next;
    }

    if (delete_node == NULL){
        printf("The node having value %d doesn't exist.\n", key);
    }else{
        previous_node->next = delete_node->next;
        free(delete_node);
        count--;
    }
}