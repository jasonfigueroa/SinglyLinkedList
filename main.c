#include <stdio.h>
#include <stdlib.h>

#include "List.h"

int main() {
    node *head;

    head = NULL;

    destroy(head);

    printList(head);
    printf("\n");

    insert(&head, 10);

    add(&head, 5);
    add(&head, 6);
    add(&head, 7);

    insert(&head, 14);

    printList(head);
    printf("\n");

    delete(&head, 5);

    printList(head);
    printf("\n");

    destroy(head);

    return 0;
}
