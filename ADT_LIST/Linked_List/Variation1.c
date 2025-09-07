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

int retrieve(List list, int index);
int locate(List list, int data);
List empty(List list);
List sortList(List list);
List deleteStart(List list);
List deleteLast(List list);
List deletePos(List list, int index);
List insertSort(List list, int data);
List insertPos(List list, int data, int index);
List insertLast(List list, int data);
List insertFirst(List list, int data);
void display(List list);
List initialize(List list);

int main(){
    List L;

    L = initialize(L);

    printf("Insert First\n");
    L = insertFirst(L, 44);
    L = insertFirst(L, 33);
    L = insertFirst(L, 22);
    L = insertFirst(L, 11);
    // sortList(L);
    display(L);

    printf("Insert Last\n");
    L = insertLast(L, 99);
    display(L);

    printf("Insert Position\n");
    L = insertPos(L, 10, 2);
    display(L);

    printf("Insert Sorted\n");
    L = insertSort(L, 50);
    display(L);

    // printf("Delete First\n");
    // deleteStart(L);
    // display(L);

    // printf("Delete Last\n");
    // deleteLast(L);
    // display(L);

    // printf("Delete Position\n");
    // deletePos(L, 2);
    // display(L);

    // printf("Retrieve Data\n");
    // int res = retrieve(L, 0);
    // if(res > 0){
    //     printf("The data retrieve from that position is %d.\n", res);
    //     display(L);
    // }else{
    //     display(L);
    // }

    // printf("Locate Data\n");
    // int got = locate(L, 33);
    // if(got > 0){
    //     printf("The data is located in position %d.\n", got);
    //     display(L);
    // }else{
    //     printf("The data did not exist in the list.\n");
    //     display(L);
    // }

    // empty(L);
    return 0;
}

int locate(List list, int data){

}

int retrieve(List list, int index){

}

List empty(List list){

}

List sortList(List list){

}

List deletePos(List list, int index){

}

List deleteLast(List list){

}

List deleteStart(List list){

}

List insertSort(List list, int data){

}

List insertPos(List list, int data, int index){
    if(index > list.count){
        printf("The index/position should be less than or equal to count.\n");
    }else if(list.head == NULL || index == 0){
        list = insertFirst(list, data);
    }else if(list.count == index){
        list = insertLast(list, data);
    }else{
        Node *newNode = (Node *)malloc(sizeof(Node));
        if(newNode == NULL){printf("Memory Allocation Failed.\n");}
        newNode->data = data;

        Node *trav = list.head;
        for(int i = 0; i < index - 1; i++){
            trav = trav->next;
        }
        Node *prev = trav;
        newNode->next = trav->next;
        prev->next = newNode;

        list.count++;
    }
    
    return list;
}

List insertLast(List list, int data){
    if(list.head == NULL){
        list = insertFirst(list, data);
    }else{
        Node *newNode = (Node *)malloc(sizeof(Node));
        if(newNode == NULL){printf("Memory Allocation Failed.\n");}
        newNode->data = data;

        Node *trav = list.head;
        for(; trav->next != NULL; trav = trav->next){} //WHY DAFAQ IT WILL NOT WORK IF ITS (trav != NULL) but will work if its (trav->next != NULL)
        trav->next = newNode;
        newNode->next = NULL;

        list.count++;
    }

    return list;
}
    
List insertFirst(List list, int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){printf("Memory Allocation Failed.\n");}
    newNode->data = data;
    newNode->next = list.head;
    
    list.head = newNode;
    list.count++;

    return list;
}

void display(List list){
    printf("Elem: [");
    for(Node *trav = list.head; trav != NULL; trav = trav->next){
        if(trav->next != NULL){
            printf("%d, ", trav->data);
        }else{
            printf("%d]\nCount: %d\n\n", trav->data, list.count);
        }
    }
    
}

List initialize(List list){
    list.head = NULL;
    list.count = 0;

    return list;
}