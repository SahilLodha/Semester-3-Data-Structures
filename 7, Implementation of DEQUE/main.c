#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int max;
    int front, rear;
} deque;

void initialize(deque *q);
int empty(deque *q);
int full(deque *q);
void ins_queue_rear(deque *);
void ins_queue_front(deque *);
int del_queue_front(deque *);
int del_queue_rear(deque *);
void print_queue(deque *);


int main() {
    int i, x, option, n;
    deque dq;

    initialize(&dq);
    do{

        printf("The Operation that can be performed are:\n");
        printf("Press 1 Insert (Front)\n");
        printf("Press 2 Insert (Rear)\n");
        printf("Press 3 Remove (Front)\n");
        printf("Press 4 Remove (Rear)\n");
        printf("Press 5 Details\n");
        printf("Press 6 Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (full(&dq)) {
                    printf("The Queue is Full. Remove Items First\n");
                } else {
                    ins_queue_front(&dq);
                }

                break;
            case 2:
                if (full(&dq)) {
                    printf("The Queue is Full. Remove Items First.");
                } else {
                    ins_queue_rear(&dq);
                }

                break;

            case 3:
                if (empty(&dq)) {
                    printf("The queue is empty. Please insert some elements.\n");
                } else {
                    x = del_queue_front(&dq);
                    printf("The popped element is %d\n", x);
                }

                break;

            case 4:
                if (empty(&dq)) {
                    printf("The queue is empty. Please insert some elements.\n");
                } else {
                    x = del_queue_rear(&dq);
                    printf("The popped element is %d\n", x);
                }

                break;

            case 5:
                print_queue(&dq);
                break;

            default:
                break;
        }
    }while(option!=6);

}

void print_queue(deque *dq) {
    printf("<----- Current Queue Details ----->\n");
    printf("Rear: %d, Front: %d\n", dq->rear, dq->front);
    printf("Size: %d\n", dq->max);
    if (empty(dq)){
        printf("No elements in Queue\n");
    }else if(full(dq)){
        for (int i = 0; i <dq->max ; ++i) {
            printf("In position %d: %d\n", i+1, dq->data[i]);
        }
    }
    else{
        for (int i = dq->front;i != dq->rear+1 ;i = (i+1)%dq->max){
            printf("In position %d: %d\n", i, dq->data[i]);
        }
    }


    printf("\n<--------- End Of Details --------->\n");
}

void initialize(deque *q) {
    q->rear = -1;
    q->front = -1;

    printf("Enter the size of the Queue to be created: ");
    scanf("%d", &(q->max));
    q->data = (int *) malloc(q->max * sizeof(int));
}

int empty(deque *q) {
    if (q->rear == -1) {
        return 1;
    }

    return 0;
}

int full(deque *q) {
    if ((q->rear + 1) % (q->max) == q->front) {
        return 1;
    }
    return 0;
}

void ins_queue_rear(deque *q) {
    int x;

    printf("Enter the number to be inserted from the rear: ");
    scanf("%d", &x);

    if (empty(q)) {
        q->rear = 0;
        q->front = 0;
        q->data[0] = x;
    } else {
        q->rear = ((q->rear) + 1) % (q->max);
        q->data[q->rear] = x;
    }
}

void ins_queue_front(deque *q) {
    int x;
    printf("Enter a number to be added from the front: ");
    scanf("%d", &x);

    if (empty(q)) {
        q->rear = 0;
        q->front = 0;
        q->data[q->front] = x;
    } else {
        q->front = ((q->front) - 1 + q->max) % (q->max);
        q->data[q->front] = x;
    }
}

int del_queue_front(deque *q) {
    int x;
    x = q->data[q->front];
    if (q->rear == q->front) {
        initialize(q);
    } else {
        q->front = (q->front + 1) % (q->max);
    }
    return x;
}

int del_queue_rear(deque *q) {
    int x;

    x = q->data[q->rear];
    if (q->rear == q->front) {
        initialize(q);
    } else {
        q->rear = (((q->rear) - 1) + q->max) % (q->max);
    }
    return x;
}