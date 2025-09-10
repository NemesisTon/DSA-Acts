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

bool isFull(List *s);
bool isEmpty(List *s);
int peek(List *s);
void pop(List *s);
void push(List *s, int data);
void display(List s);
List* initialize();


int main(){
    List *L = initialize();

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
        printf("The top most list is %d.\n", got);    
    }
    display(*L);

    printf("Empty Stack List\n");
    int empty = isEmpty(L);
    if(empty == 1){
        printf("Is it empty? Yes.\n");    
    }else{
        printf("Is it empty? No.\n");
    }
    display(*L);

    printf("Full Stack List\n");
    int full = isFull(L);
    if(full == 1){
        printf("Is it full? Yes.\n");    
    }else{
        printf("Is it full? No.\n");    
    }
    display(*L);
    return 0;
}

bool isFull(List *s){
    if(s->count == MAX){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(List *s){
    if(s->head == NULL){
        return true;
    }else{
        return false;
    }
}

int peek(List *s){
    if(s->head == NULL){
        printf("The list is empty.\n");
        return -1;
    }
    int got = - 1;
    
    Node *trav = s->head;
    for(; trav->next != NULL; trav = trav->next){}
    got = trav->data;

    return got > 0 ? got : - 1;
}

void pop(List *s){
    if(s->count == MAX){
        printf("The linked list is full.\n");
    }else if(s->count == 1){
        Node *trav = s->head;
        free(trav);
        s->head = NULL;
        s->count--;
        printf("The list is empty.\n");
    }else{
        Node *trav = s->head, *prev = trav;
        trav = trav->next;
        for(; trav->next != NULL; trav = trav->next, prev = prev->next){}
        free(trav);
        prev->next = NULL;
        s->count--;
    }
}

void push(List *s, int data){
    if(s->count == MAX){
        printf("The linked list is full.\n");
    }else{
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;

        if(s->head == NULL){
            s->head = newNode;
            newNode->next = NULL;
        }else{
            Node *trav = s->head;
            for(; trav->next != NULL; trav = trav->next){}
            trav->next = newNode;
            newNode->next = NULL;
        }
        s->count++;
    }
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
    List *list = (List *)malloc(sizeof(List));
    
    list->head = NULL;
    list->count = -1;

    return list;
}