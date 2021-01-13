#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *left;
    struct Node *right;
    int node_data;
};

struct Node* Delete(struct Node*, int);
void Insert(int);
void Traverse(struct Node *);
void Search(int);
struct Node *root = NULL;

int main() {
    int size, element, option;
    printf("<----- Menu Starts Here ----->"
           "\nPress 1: Insert one element "
           "\nPress 2: Insert 'n' Elements"
           "\nPress 3: Remove Node"
           "\nPress 4: Traverse (sort ascending)"
           "\nPress 5: Search"
           "\nPress 6: Exit"
           "\n<------ Menu Ends Here ------>\n");

    do{
        printf("Please Choose option from the Menu: ");
        scanf("%d", &option);

        if(option==1){

            printf("Enter an Element: ");
            scanf("%d",&element);
            Insert(element);

        }else if(option==2){

            printf("Enter the no of initial values in the tree: ");
            scanf("%d", &size);
            for(int i = 0; i<size; i++){
                printf("Enter element %d: ",i+1);
                scanf("%d", &element);
                Insert(element);

            }
        }else if(option==4) {

            printf("Node Value in Sorted Order is presented below: \n");
            Traverse(root);
            printf("\n");

        }else if(option==5){

            printf("Enter The value to be searched for: ");
            scanf("%d", &element);
            Search(element);

        }else if(option==6){

            printf("<---------- Thank you ---------->");

        }else if(option==3){

            printf("Enter the value to be removed: ");
            scanf("%d",&element);
            Delete(root, element);

        }else{
            printf("Enter a Valid Option Please!");
        }
    }while (option!=6);
}

void Insert(int key){
    struct Node *t = root;
    struct Node *r, *new_node;

    r = (struct Node*)malloc(sizeof(struct Node));

    if (root==NULL){
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->node_data = key;
        root=new_node;
        new_node->left = new_node->right = NULL;
    }

    while (t!=NULL){
        r = t;
        if(key<t->node_data){
            t = t->left;
        }else if(key>t->node_data){
            t = t->right;
        }else{
            return;
        }
    }

    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->node_data = key;
    new_node->left = new_node->right = NULL;

    if(key<r->node_data) r->left = new_node;
    else r->right = new_node;
}

void Traverse(struct Node *p){
    if (p){
        Traverse(p->left);
        printf("%d ", p->node_data);
        Traverse(p->right);
    }
}

void Search(int key){
    struct Node *temp=root;

    while(temp!=NULL)
    {
        if(key==temp->node_data){
            printf("Element Found!\n");
            return;
        }
        else if(key<temp->node_data)
            temp=temp->left;
        else
            temp=temp->right;
    }
    printf("Element Not Found\n");
}

int Height(struct Node *node){
    int x,y;
    if(node == NULL)return 0;
    x=Height(node->left);
    y=Height(node->right);
    return x>y?x+1:y+1;
}


struct Node *InPre(struct Node *node){
    while(node && node->right != NULL)
        node=node->right;

    return node;
}

struct Node *InSucc(struct Node *node){
    while(node && node->left != NULL)
        node=node->left;

    return node;
}

struct Node* Delete(struct Node *node,int key){
    struct Node *q;

    if(node==NULL)
        return NULL;
    if(node->left==NULL && node->right==NULL)
    {
        if(node==root)
            root=NULL;
        free(node);
        return NULL;

    }

    if(key < node->node_data)
        node->left=Delete(node->left,key);
    else if(key > node->node_data)
        node->right=Delete(node->right,key);
    else
    {
        if(Height(node->left)>Height(node->right))
        {
            q=InPre(node->left);
            node->node_data=q->node_data;
            node->left=Delete(node->left,q->node_data);
        }
        else
        {
            q=InSucc(node->right);
            node->node_data=q->node_data;
            node->right=Delete(node->right,q->node_data);
        }
    }
    return node;
}