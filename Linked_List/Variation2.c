#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    int count;
}List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
// void deletePos(List *list, int index);
// int retrieve(List *list, int index);
// int locate(List *list, int data);
void display(List *list);

int main(){
    List *L;

    L = initialize();
    insertFirst(L, 11);
    insertFirst(L, 22);
    insertFirst(L, 33);
    // insertPos(L, 55, 2);
    // insertLast(L, 99);
    // empty(L);
    // deleteStart(L);
    deleteLast(L);
    display(L);

    return 0;
}

void deleteLast(List *list){
    Node *trav, *curr;

    for(trav = list->head; trav->next != NULL; trav = trav->next){
        curr = trav;
    }
    trav = curr->next;
    free(trav);
    curr->next = NULL;

    list->count--;
}

void deleteStart(List *list){
    Node *trav;

    trav = list->head;
    list->head = trav->next;
    free(trav);
    list->count--;
}

void empty(List *list){
    Node *trav, *prev;
    for(trav = list->head; trav != NULL;){
        prev = trav->next;
        free(trav);
        list->head = prev;
        trav = prev;
    }
    list->head = NULL;
    list->count = 0;
}

void insertPos(List *list, int data, int index){
    if(list->head == NULL){
        insertFirst(list, data);
    }else if(list->count == index){
        insertLast(list, data);
    }else{
        Node *trav, *prev;

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;

        for(trav = list->head; list->count < index - 1; trav = trav->next){}
        prev = trav->next;
        trav->next = newNode;
        newNode->next = prev;
        list->count++;
    }
}

void insertLast(List *list, int data){
    Node *trav;

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if(list->head == NULL){
        list->head = newNode;    
    }else{
        for(trav = list->head; trav->next != NULL; trav = trav->next){}
        trav->next = newNode;
    }
    list->count++;
}
    
void insertFirst(List *list, int data){
    List *temp = list;

    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        printf("Memory allocation failed.\n");
    }
    newNode->data = data;
    newNode->next = temp->head;

    list->head = newNode;
    list->count++;
}

void display(List *list){
    printf("Linked List Elem: [");
    Node *trav;
    if(list->count == 1){
        printf("%d]", list->head->data);
    }else{
        for(trav = list->head; trav->next != NULL; trav = trav->next){
            printf("%d, ", trav->data);
            if(trav->next->next == NULL){
                printf("%d]", trav->next->data);
            }
        }    
    }
}

List* initialize(){
    List *L = (List *)malloc(sizeof(List));
    if(L == NULL){
        printf("Memory allocation failed.");
    }
    L->head = NULL;
    L->count = 0;
}