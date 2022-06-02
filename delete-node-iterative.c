#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
void push(struct Node** href, int ndata){
    struct Node* nnode= (struct Node*) malloc(sizeof(struct Node));
    nnode->data =ndata;
    nnode->next =(*href);
    (*href) =nnode;
}
void deleteNode(struct Node** href, int key){
    struct Node *temp = *href, *prev;
    if(temp!=NULL&&temp->data == key){
        *href = temp->next;
        free(temp);
        return;
    }
    while (temp !=NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return;
    }
    prev->next =temp->next;
    free(temp);
}
void printList(struct Node* node)
{
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 1);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    puts("");
    puts("Teminated");
    return 0;
}
