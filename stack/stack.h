



#define increase 1
#define reduce 0

struct stack {

    int* data;

    size_t size;

    size_t capacity;
};


int StackCtor_  (stack *stk, size_t cap);

int Push        (stack *stk, int input);

int Pop         (stack *stk);

int StackResize (stack *stk, int mod);

int StackDump   (stack *stk);

int StackDtor_  (stack *stk);


int StackCtor_ (stack *stk, size_t cap) {

    stk -> data = (int*) calloc (cap, sizeof (int));

    stk -> size = 0;

    stk -> capacity = cap;

    return 0;
}



int Push (stack *stk, int input) {

    if ((stk -> size) == (stk -> capacity)) StackResize (stk, increase);

    *((stk -> data) + (stk -> size)) = input;

    (stk -> size)++;

    return 0;
}



int Pop (stack *stk) {

    int output = *((stk -> data) + (stk -> size));

    *((stk -> data) + (stk -> size)) = 0;

    (stk -> size)--;

    if ((stk -> size) <= (stk -> capacity)/4) StackResize (stk, reduce);

    return output;
}



int StackResize (stack* stk, int mod) {

    if (mod) {

        stk -> data = (int*) realloc ((void*) (stk -> data), sizeof(int) * (stk -> capacity)*2);

        stk -> capacity *= 2;
    }

    else {

        stk -> data = (int*) realloc ((void*) (stk -> data), sizeof(int) * (stk -> capacity)/2);

        stk -> capacity /= 2;
    }

    return 0;
}



int StackDump   (stack *stk) {

    for (unsigned int i = 0; i < (stk -> size); i++) printf ("%d ", (stk -> data)[i]);

    printf ("\n");

    return 0;
}



int StackDtor_ (stack* stk) {

    free ((void*) (stk -> data));

    stk -> data = (int*) 0;

    stk -> size = -1;

    stk -> capacity = -1;

    return 0;
}
