#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

bool isFull(Stack *s);
bool isEmpty(Stack *s);
int peek(Stack *s);
void pop(Stack *s);
void push(Stack *s, int data);
void display(Stack s);
Stack* initialize();

#endif