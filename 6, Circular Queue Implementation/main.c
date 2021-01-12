#include <stdio.h>
#include <stdlib.h>

#define INITIAL -1
typedef struct {
    int *queue;
    int front;
    int rear;
    int size;
} queue;

void allocate(queue *);
int isEmpty(queue *);
int isFull(queue *);
void push(queue *);
void pop(queue *);
void details(queue *);

int main() {
    queue q;
    int decision;
    int perform;
    printf("Enter the Size of the queue: ");
    scanf("%d", &q.size);
    // Creating a queue of provided size...
    allocate(&q);
    do {
        printf("Note:"
               "\nPress to view current Details"
               "\nPress 1 to Push and "
               "\nPress 2 to Pop: ");
        scanf("%d", &perform);
        if (perform == 1) {
            push(&q);
        } else if (perform == 2) {
            pop(&q);
        } else {
            details(&q);
        }
        printf("To continue press [1] and to exit press [0/Any Other]:");
        scanf("%d", &decision);
    } while (decision == 1);
    return 0;
}

void details(queue *q) {
    printf("The details are:\n"
           "Front = %d\nRear = %d\n", q->front, q->rear);
    printf("Front\t");
    for (int i = 0; i < q->size; ++i) {
        printf("%d\t", q->queue[i]);
    }
    printf(": Rear\n");
}

void allocate(queue *q) {
    (q->queue) = (int *) malloc((q->size) * sizeof(int));
    printf("Allocation Successful\nQueue Created\n\n");
    q->front = q->rear = INITIAL; // Initial condition in a queue.
}

int isEmpty(queue *q) {
    if ((q->front) == INITIAL && (q->rear) == INITIAL) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(queue *q) {
    if (q->rear == (q->size) - 1) {
        return 1;
    } else {
        return 0;
    }
}

void push(queue *q) {
    if (isFull(q)) {
        printf("The Queue is full.\n Try Popping out Elements first.\n");
    } else {
        q->rear += 1;
        if (q->rear == 0) {
            q->front = 0;
        }
        printf("Enter The element to be pushed: ");
        scanf("%d", &(q->queue)[q->rear]);
        printf("Value Inserted\n");
    }
}

void pop(queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("The value cannot be popped. "
               "\nQueue is empty."
               "\nTry Pushing Elements.\n");
    } else {
        item = (q->queue)[q->front];
        (q->queue)[q->front++] = 0;
        if (q->front > q->rear) {
            q->front = q->rear = INITIAL;
        }
        printf("The Popped element is %d\n", item);
    }
}