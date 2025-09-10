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

    return 0;
}

int peek(List *s){
    
}

void pop(List *s){
    if(s->count == MAX){
        printf("The linked list is full.\n");
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
    printf("%-50s Count: %d\n\n", buffer, s.count);
}

List* initialize(){
    List *list = (List *)malloc(sizeof(List));
    
    list->head = NULL;
    list->count = 0;

    return list;
}