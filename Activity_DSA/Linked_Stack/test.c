#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

bool isFull(List *s){
    return s->count == MAX - 1;
}

bool isEmpty(List *s){
    return s->count == - 1;
}

int peek(List *s){

}

void pop(List *s){

}

void push(List *s, int data){
    
}

void display(List s){
    char buffer[256] = "Elem: [";
    char temp[20];
    
    Node *trav = s.head;
    while(trav != NULL){
        if(trav->next != NULL){
            sprintf(temp, "%d, ", trav->data);
        }else{
            sprintf(temp, "%d]", trav->data);
        }
        strcat(buffer, temp);
        trav = trav->next;
    }
    printf("%-50s Count: %d\n\n", buffer, s.count + 1);
}

List* initialize(){
    List *s = (List *)malloc(sizeof(List));
    s->count = -1;
    return s;
}


int main(){
    List *L = initialize();

    printf("Push Stack List\n");
    push(L, 10);
    push(L, 20);
    push(L, 30);
    push(L, 40);
    display(*L);

    // printf("Pop Stack List\n");
    // pop(L);
    // display(*L);

    // printf("Peek Stack List\n");
    // int got = peek(L);
    // if(got > 0){
    //     printf("The top most list is %d.\n", got);    
    // }
    // display(*L);

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