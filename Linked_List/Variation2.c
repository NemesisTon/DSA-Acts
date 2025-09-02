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
void deletePos(List *list, int index);
// int retrieve(List *list, int index);
// int locate(List *list, int data);
// void insertSort(List *list, int data);
// void sortList(List *list);
void display(List *list);

int main(){
    List *L;

    L = initialize();
    insertFirst(L, 44);
    insertFirst(L, 33);
    insertFirst(L, 22);
    insertFirst(L, 11);
    // insertLast(L, 99);
    // empty(L);
    // deleteStart(L);
    // deleteLast(L);
    deletePos(L, 5);
    display(L);

    return 0;
}
void deletePos(List *list, int index){
    if(index > list->count){
        printf("The index should be less than or equal to count.\n");
    }else if(index == 0){
        deleteStart(list);
    }else if(index == list->count){
        deleteLast(list);
    }else{
        Node *trav;
    }
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
    if(index > list->count){
        printf("Invalid index it should be less than or equal to count.\n");
    }else if(list->head == NULL || index == 0){
        insertFirst(list, data);
    }else if(list->count == index){
        insertLast(list, data);
    }else{
        Node *trav, *prev;

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        
        trav = list->head;
        for(int i = 0; i < index - 1; i++){
            trav = trav->next;
        }
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