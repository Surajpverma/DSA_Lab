// Include the stack implementation in your code. You can use either the linked list implementation or the array implementation.
#include <stdio.h>
#include "stack.h"

void computeSpans(int *inputs, int *spans, int n);

Element itoe (int i)
{
    Element e;
    e.int_value = i;
    e.float_value = 0;
    return e;
}

int main()
{
    int inputs[] = {6, 3, 4, 5, 2};
    int spans[5];
    computeSpans(inputs, spans, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", spans[i]);
    }
    printf("\n");
    int inputs2[] = {100, 80, 60, 70, 60, 75, 85};
    int spans2[7];
    computeSpans(inputs2, spans2, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", spans2[i]);
    }
    printf("\n");
    return 0;
}

void computeSpans(int *inputs, int *spans, int n)
{
    Stack* s = newStack();
    for (int i = 0; i < n; ++i)
    {
        while(!isEmpty(s) && inputs[top(s)->int_value] <= inputs[i]){
            pop(s);
        }    
        if (isEmpty(s))
        {
            spans[i] = i + 1;
        }
        else{
            spans[i] = i - top(s)->int_value;
        }
        push(s, itoe(i));
    }
}