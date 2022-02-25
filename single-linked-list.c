#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void printList(struct Node* n){
    while(n!=NULL){
        printf(" %d ", n->data);
        n= n->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    // allocate 3 nodes in the heap - y���nda 3 d���m alan� tahsis eder
    head =(struct Node*) malloc(sizeof (struct Node));
    second =(struct Node*) malloc(sizeof (struct  Node));
    third = (struct Node*) malloc(sizeof (struct Node));

    head->data = 1; // assign data in first node- ilk d���me de�er atama
    head->next = second; //  link first node with the second node-ilk d���m ikinci d���m ile ba�lan�r

    second->data =2; // assign data in second node
    second->next = third; // node connects to other node

    third->data =3; // assign data in thrid node
    third->next = NULL;

    printList(head);
    free(head);
    free(second);
    free(third);
    puts("Terminated");
    return 0;
}
