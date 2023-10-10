#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Stack;

void Push(Stack** top, int data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int Pop(Stack** top) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        exit(-1);
    }
    int data = (*top)->data;
    Stack* temp = *top;
    *top = (*top)->next;
    free(temp);
    return data;
}

int IsEmpty(Stack* top) {
    return top == NULL;
}

void Print_Stack(Stack* top) {
    Stack* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack* stack;

    Push(&stack, 10);
    Push(&stack, 20);
    Push(&stack, 30);

    printf("Stack: ");
    Print_Stack(stack);

    int popped = Pop(&stack);
    printf("Popped: %d\n", popped);

    printf("Stack: ");
    Print_Stack(stack);

    return 0;
}

