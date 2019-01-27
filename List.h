//
// Created by Jason on 1/26/2019.
//

#ifndef SINGLYLINKEDLIST_LIST_H
#define SINGLYLINKEDLIST_LIST_H

typedef struct node {
    int value;
    struct node *next;
} node;

void add(node **head, int value);
void insert(node **head, int value);
void delete(node **head, int value);
void printList(node *head);
void destroy(node *head);

#endif //SINGLYLINKEDLIST_LIST_H
