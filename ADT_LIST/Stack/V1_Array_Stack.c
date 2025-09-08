#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack;

bool isFull(Stack *s);
bool isEmpty(Stack *s);
int peek(Stack *s);
void pop(Stack *s);
void push(Stack *s, int value);
void display(Stack *s);
Stack* initialize();


int main(){
    Stack *s = initialize();
    
    printf("Insert/Push in Stack Array\n");
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    display(s);

    printf("Delete in Stack Array\n");
    pop(s);
    display(s);

    printf("Peek in Stack Array\n");
    int got = peek(s);
    if(got >= 0){
        printf("The data at the top in the stack array is %d.\n", got);
        display(s);
    }else{
        display(s);
    }
    
    printf("Empty in Stack Array\n");
    printf("Is the array empty? %d\n\n", isEmpty(s));

    printf("Full in Stack Array\n");
    printf("Is the array full? %d\n\n", isFull(s));

    return 0;
}

bool isFull(Stack *s){
    if(s->top == MAX){
        return true;
    }else{
        return false;
    } 
}

bool isEmpty(Stack *s){
    if(s->top == -1){
        return true;
    }else{
        return false;
    } 
}

int peek(Stack *s){
    int got = 0;
    if(s->top == -1){
        printf("The stack array is empty.\n\n");
    }else{
        got = s->items[s->top];
    }
    return got;
}

void pop(Stack *s){
    if(s->top == -1){
    }else{
        s->top--;
    }
}

void push(Stack *s, int value){
    if(s->top != MAX){
        s->top++;
        s->items[s->top] = value;
    }else if(s->top == MAX){
        printf("The array is full.\n");
    }
}

void display(Stack *s){
    if(s->top == -1){
        printf("Stack array is empty.\n\n");
    }else{
        printf("Elem: [");
        for(int i = s->top; i >= 0; i--){
            if(i != 0){
                printf("%d, ", s->items[i]);
            }else{
                printf("%d]\n\n", s->items[i]);
            }
        }
    }
}

Stack* initialize(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->top = - 1;
    
    return s;
}