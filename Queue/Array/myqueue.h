#include <stdio.h>
#include <stdbool.h>

struct myqueue{
    int Q[100];
    int front;
    int rear;
    int maxsize;
};

typedef struct myqueue * myqueuep;

myqueuep new();

void Enqueue(myqueuep,int);

void Dequeue(myqueuep);

int Front(myqueuep);

bool IsEmpty(myqueuep);

int size(myqueuep);