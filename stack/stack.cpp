#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {

    stack stk = {};

    StackCtor_ (&stk, 3);

    for (int i = 1; i < 26; i++) {

         Push (&stk, i);

         StackDump (&stk);

         printf ("%d %d\n\n\n", stk.size, stk.capacity);
    }

    StackDtor_ (&stk);

    return 0;
}
