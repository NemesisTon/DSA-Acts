#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkStack.h"

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct Stack{
    Node *top;
}Stack;

bool isFull(Stack *s){
    return false;
}

bool isEmpty(Stack *s){
    return s->top == NULL;
}

int peek(Stack *s){
    int found = - 1;
    if(!isEmpty(s)){
        found = s->top->data;
    }else{
        printf("The list is empty.\n\n");
    }

    return found;
}

void pop(Stack *s){
    if(!isEmpty(s)){
        s->top = s->top->next;
    }else{
        printf("The list is empty.\n");
    }
}

void push(Stack *s, int data){
    if(!isFull(s)){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = s->top;
        s->top = newNode;
    }else{
        printf("The Stack is empty.\n");
    }
}

void display(Stack s){
    char buffer[256] = "Elem: [Top Most --> ";
    char temp[20];
    
    Node *trav = s.top;
    int i = 0;
    while(trav != NULL){
        if(trav->next != NULL){
            sprintf(temp, "%d --> ", trav->data);
        }else{
            sprintf(temp, "%d --> NULL]", trav->data);
        }
        strcat(buffer, temp);
        trav = trav->next;
        i++;
    }
    printf("%-75s Count: %d\n\n", buffer, i);
}

Stack* initialize(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}