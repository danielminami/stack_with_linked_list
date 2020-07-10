/*
Daniel Minami <minamid@sheridancollege.ca>
----------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *top = NULL;

bool isEmpty() {
    return top == NULL;
}

node_t* createNode(int newValue) {
    node_t* newNode = (node_t*) malloc( sizeof(node_t) );
    newNode->data = newValue;
    newNode->next = NULL;
    return newNode;
}

void push(int newValue) {
    if (top == NULL) {
        top = createNode(newValue);
    } else {
        node_t* newNode = createNode(newValue);
        newNode->next = top;
        top = newNode;
    }
}

int pop() {
    if (isEmpty()) {
        printf("List is empty");
        return;
    }
    
    node_t* poppedItem = top;
    top = top->next;
    return poppedItem->data;
}

void printStack() {
    printf("Printing all elements: \n");
    node_t* current = top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    printStack();
    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());
    printf("Popped item: %d\n", pop());
    push(6);
    printStack();
    
    return 0;
}

