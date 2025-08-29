#include <stdio.h>

#define MAX 10

typedef struct 
{
    int elem[MAX];
    int count;
}List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

int main(){
    List L;
    
    initialize(L);
    L.elem[0] = 0;
    L.elem[1] = 11;
    L.elem[2] = 22;
    L.elem[3] = 33;
    L.elem[4] = 44;
    L.count = 5;

    printf("1. Insert 77 in Position 2: \n");
    L = insertPos(L, 77, 2);
    display(L);
    
    printf("\n\n");

    printf("2. Delete Position 2: \n");
    L = deletePos(L, 2);
    display(L);

    printf("\n\n");

    printf("3. Locate 44 in the array.\n");
    int res = locate(L, 44);
    if(res > 0){
        display(L);
        printf("\nData is located in position %d of the array.", res);
    }else{
        display(L);
        printf("\nData did not exist.");
    }

    printf("\n\n");

    printf("4. Insert sorted #25 in the array.\n");
    L = insertSorted(L, 25);
    display(L);

    return 0;
}

List initialize(List L){
    L.count = 0;

    return L;
}

List insertPos(List L, int data, int position){
    if(position > L.count){
        printf("Invalid position it should be less than or equal to count.\n");
        return L;
    }else if(L.count >= MAX){
        printf("The array is full.\n");
        return L;
    }

    for(int i = L.count, temp; i >= position; i--){
        L.elem[i] = L.elem[i - 1];
        if(position == i){
            L.elem[i] = data;
        }
    }
    L.count++;

    return L;
}

List deletePos(List L, int position){
    if(position > L.count){
        printf("Invalid position it should be less than or equal to count.\n");
        return L;
    }

    for(int i = position; i < L.count; i++){
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;

    return L;
}

int locate(List L, int data){
    int found = 0;
    for(found = 0; found < L.count && L.elem[found] != data; found++){}

    return found + 1 > L.count ? -1 : (found + 1);
}

List insertSorted(List L, int data){
    if(L.count >= MAX){
        printf("The count should not be equal or greater than length (10).\n");
    }

    int pos = 0;
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] > data && L.elem[i - 1] < data){
            pos = i;
        }
    }
    printf("P: %d\t", pos);

    for(int i = L.count; i >= pos; i--){
        L.elem[i] = L.elem[i - 1];
        if(i == pos){
            L.elem[i] = data;
        }
    }
    L.count++;

    return L;
}

void display(List L){
    printf("Elem: [");
    for(int i = 0; i < L.count; i++){
        if(i + 1 < L.count){
            printf("%d, ", L.elem[i]);
        }else{
            printf("%d]", L.elem[i]);
        }
    }
}