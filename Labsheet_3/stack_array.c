#include "element.h"
#include "stack.h"
#include <stdlib.h>
#define STACK_SIZE 1000
struct Stack
{
    int top;
    Element data[STACK_SIZE];
};

Stack *newStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if(s != NULL)
        s->top = -1;
    return s;
}

bool push(Stack *s, Element e)
{
    if(s->top == STACK_SIZE - 1)
        return false;
    s->data[++(s->top)] = e;
    return true;
}

Element *top(Stack *stack){
    if (stack->top == -1)
    {
        return NULL;
    }
    return &stack->data[stack->top];
}

bool pop(Stack *stack){
    if (stack->top == -1)
    {
        return false;
    }
    else {--(stack->top);}
    return true;
}

bool isEmpty(Stack *stack){
    if (stack->top == -1)
    {
        return true;
    }
    return false;
}

void freeStack(Stack *stack){
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}













