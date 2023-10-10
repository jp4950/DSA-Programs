#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myqueue.h"

myqueuep new(){
    myqueuep queue;
    queue = (myqueuep)malloc(sizeof(struct myqueue));
    queue->front = 0;
    queue->rear = 0;
    queue->maxsize = 3;
    return queue;
}

int size(myqueuep queue){
    return (queue->maxsize + queue->rear - queue->front) % queue->maxsize;
}


bool IsEmpty(myqueuep queue){
    return (queue->front == queue->rear);
}

void Enqueue(myqueuep queue,int data){
    if(size(queue) == queue->maxsize-1){
        printf("Queue is full");
        return; 
    }
    queue->Q[queue->rear] = data;
    queue->rear=(queue->rear + 1)%queue->maxsize;
}

void Dequeue(myqueuep queue){
    if(IsEmpty(queue)){
        printf("Queue is empty");
        return;
    }
    queue->front=(queue->front + 1)%queue->maxsize;

}

int Front(myqueuep queue){
    if(IsEmpty(queue)){
        printf("Queue is empty");
    }else{
        return queue->Q[queue->front];
    }
}
