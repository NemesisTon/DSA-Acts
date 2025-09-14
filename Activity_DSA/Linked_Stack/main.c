#include <stdio.h>
#include "linkStack.h"

int main(){
    Stack *L = initialize();

    printf("Push Stack List\n");
    push(L, 10);
    push(L, 20);
    push(L, 30);
    push(L, 40);
    display(*L);

    printf("Pop Stack List\n");
    pop(L);
    display(*L);

    printf("Peek Stack List\n");
    int got = peek(L);
    if(got > 0){
        printf("The top most Stack is %d.\n", got); 
        display(*L);   
    }

    printf("Empty Stack List\n");
    int empty = isEmpty(L);
    if(empty == 1){
        printf("Is it empty? Yes.\n\n");    
    }else{
        printf("Is it empty? No.\n\n");
    }

    printf("Full Stack List\n");
    int full = isFull(L);
    if(full == 1){
        printf("Is it full? Yes.\n\n");    
    }else{
        printf("Is it full? No.\n\n");    
    }

    return 0;
}