#include <stdio.h>
#include "arrStack.h"

int main() {
    Stack *s = initialize();
    
    printf("Push\n");
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    display(s);

    printf("Pop\n");
    pop(s);
    display(s);

    printf("Top element: %d\n", peek(s));

    return 0;
}
