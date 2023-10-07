#include <stdlib.h>
#include <stdio.h>

//Creating the structure for the linked list
typedef struct node {
    int data;
    struct node *next;
} arrayL;

//Creating the Linked List
arrayL* Create_AL() {
    arrayL *temp;
    temp = (arrayL *)malloc(sizeof(arrayL));
    temp->data = 0;
    temp->next = NULL;
    return temp;
}

//Function which can insert data at the front of the list
void InsertAtBeg_AL(arrayL **head, int data) {
    if((*head)->data == 0){ //For eliminating the zero we first initialized with the Linked list with
        (*head)->data = data;
    }else{
        arrayL *temp = (arrayL *)malloc(sizeof(arrayL));
        temp->data = data;
        temp->next = *head;
        *head = temp;
    }
}

//Function which can insert data at the given position
void InsertAtPos_AL(arrayL **head, int data, int pos) {
    arrayL *temp = (arrayL *)malloc(sizeof(arrayL));
    temp->data = data;
    
    if (*head == NULL && pos > 1) {
        printf("Invalid position.\n");
        return;
    } else if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    } else if (pos == 1) { //Basically InsertAtBeg_AL()
        temp->next = *head;
        *head = temp;
    } else {
        arrayL *temp2 = *head;
        for (int i = 0; i < pos - 2 && temp2 != NULL; i++) {
            temp2 = temp2->next;
        }
        if (temp2 == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp->next = temp2->next;
        temp2->next = temp;
    }
}


//Function which can delete at the beginning of the Linked List
void DeleteAtBeg_AL(arrayL **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    arrayL *temp = *head;
    *head = (*head)->next;
    free(temp);
}

//Function which can delete at the given position of the linked list
void DeleteAtPos_AL(arrayL **head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }
    
    if (pos == 1) {
        arrayL *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    
    arrayL *prev = NULL;
    arrayL *curr = *head;
    int count = 1;
    
    while (curr != NULL && count < pos) {
        prev = curr;
        curr = curr->next;
        count++;
    }
    
    if (curr == NULL) {
        printf("Invalid position.\n");
        return;
    }
    
    prev->next = curr->next;
    free(curr);
}


//Print the data in the linked list;
void Print_AL(arrayL *head) {
    arrayL *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}