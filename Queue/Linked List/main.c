#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Queue;

void Enqueue(Queue** front, Queue** rear, int data) {
    Queue* newNode = (Queue*)malloc(sizeof(Queue));
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int Dequeue(Queue** front, Queue** rear) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        exit(-1);
    }
    int data = (*front)->data;
    Queue* temp = *front;

    if (*front == *rear) {
        *front = NULL;
        *rear = NULL;
    } else {
        *front = (*front)->next;
    }

    free(temp);
    return data;
}

int IsEmpty(Queue* front) {
    return front == NULL;
}

void Print_Queue(Queue* front) {
    Queue* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* front = NULL;
    Queue* rear = NULL;

    Enqueue(&front, &rear, 10);
    Enqueue(&front, &rear, 20);
    Enqueue(&front, &rear, 30);

    printf("Queue: ");
    Print_Queue(front);

    int dequeued = Dequeue(&front, &rear);
    printf("Dequeued: %d\n", dequeued);

    printf("Queue: ");
    Print_Queue(front);

    return 0;
}

