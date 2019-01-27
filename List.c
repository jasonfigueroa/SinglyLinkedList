//
// Created by Jason on 1/26/2019.
//

#include <stdio.h>
#include <stdlib.h>

#include "List.h"

void add(node **head, int value) {
    node *temp;

    if((*head) == NULL) {
        (*head) = (node*)malloc(sizeof(node));
        (*head)->value = value;
        (*head)->next = NULL;
        return;
    }

    temp = (*head);

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = (node*)malloc(sizeof(node));
    temp = temp->next;
    temp->value = value;
    temp->next = NULL;
}

void insert(node **head, int value) {
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->value = value;
    temp->next = (*head);
    (*head) = temp;
}

void delete(node **head, int value) {
    node **temp;
    temp = head;

    node *nodeToDelete;

    //if target node is head
    if((*temp)->value == value) {
        nodeToDelete = (*temp);
        (*temp) = (*temp)->next;
        nodeToDelete->next = NULL;
        free(nodeToDelete);
        return;
    }

    //if target is not head
    else if((*temp)->next->value == value) {
        nodeToDelete = (*temp)->next;
        (*temp)->next = (*temp)->next->next;
        nodeToDelete->next = NULL;
        free(nodeToDelete);
        return;
    }

    delete(&((*temp)->next), value);
}

void printList(node *head) {
    node *temp;

    if(head == NULL) {
        printf("empty list");
        return;
    }

    temp = &(*head);

    printf("%d ", temp->value);

    if(temp->next == NULL) {
        return;
    }

    printList(temp->next);
}

void destroy(node *head){

    if(head == NULL) {
        printf("list is empty, nothing to destroy\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        return;
    }

    destroy(head->next);
    head->next = NULL;
    free(head);
}