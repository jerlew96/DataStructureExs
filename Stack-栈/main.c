
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct Stack{
    E* array;
    int capacity;
    int top;
};

typedef struct Stack *ArrayStack;

bool initStack(ArrayStack stack){
    stack->capacity = 10;
    stack->array = malloc(sizeof(*stack->array)*stack->capacity);
    if(!stack->array){
        return 0;
    }
    stack->top = -1;
    return 1;
}

bool pushStack(ArrayStack stack, E element){
    if(stack->top+1 == stack->capacity){
        int newCapacity = stack->capacity + (stack->capacity>>1);
        E * newArray = realloc(stack->array, newCapacity*sizeof (E));
        if(newArray == NULL){
            return 0;
        }
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[++stack->top] = element;
    return 1;
}

bool isEmpty(ArrayStack stack){
    if(stack->top == -1){
        return 0;
    }
    return 1;
}



int main() {
    struct Stack stack;
    initStack(&stack);

    for(int i = 1; i<12; i++){
        pushStack(&stack, i*100);
    }

    for(int i=0; i<=stack.top; i++){
        printf("%d ", stack.array[i]);
        printf("\n");
    }

    return 0;
}
