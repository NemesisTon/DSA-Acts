#ifndef ARRSTACK_H
#define ARRSTACK_H

#include <stdbool.h>

#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack;

bool isFull(Stack *s);
bool isEmpty(Stack *s);
int peek(Stack *s);
void pop(Stack *s);
void push(Stack *s, int value);
void display(Stack *s);
Stack* initialize();

#endif
