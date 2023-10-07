#include <stdlib.h>
#include <stdio.h>

//Creating the structure for the doubly linked list
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} arrayDL;

//Creating the Doubly Linked List
arrayDL* Create_DL() {
    arrayDL *temp;
    temp = (arrayDL *)malloc(sizeof(arrayDL));
    temp->data = 0;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

// Function to insert data at the front of the list
void InsertAtBeg_DL(arrayDL **head, int data) {
    if ((*head)->data == 0) {
        (*head)->data = data;
    } else {
        arrayDL *temp = (arrayDL *)malloc(sizeof(arrayDL));
        temp->data = data;
        temp->prev = NULL;
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
}

// Function to insert data at the given position
void InsertAtPos_DL(arrayDL **head, int data, int pos) {
    arrayDL *temp = (arrayDL *)malloc(sizeof(arrayDL));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    if (*head == NULL && pos > 1) {
        printf("Invalid position.\n");
        return;
    } else if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    } else if (pos == 1) {
        temp->next = *head;
        if (*head != NULL) {
            (*head)->prev = temp;
        }
        *head = temp;
    } else {
        arrayDL *temp2 = *head;
        for (int i = 0; i < pos - 2 && temp2 != NULL; i++) {
            temp2 = temp2->next;
        }
        if (temp2 == NULL) {
            printf("Invalid position.\n");
            return;
        }
        temp->next = temp2->next;
        temp->prev = temp2;
        if (temp2->next != NULL) {
            temp2->next->prev = temp;
        }
        temp2->next = temp;
    }
}

// Function to delete at the beginning of the Doubly Linked List
void DeleteAtBeg_DL(arrayDL **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    arrayDL *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete at the given position of the Doubly Linked List
void DeleteAtPos_DL(arrayDL **head, int pos) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        arrayDL *temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    arrayDL *curr = *head;
    int count = 1;

    while (curr != NULL && count < pos) {
        curr = curr->next;
        count++;
    }

    if (curr == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }

    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }

    free(curr);
}

// Print the data in the Doubly Linked List
void Print_DL(arrayDL *head) {
    arrayDL *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
