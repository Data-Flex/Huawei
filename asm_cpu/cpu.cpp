#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "stack.h"


struct cpu {

    int* code = {0};
    stack stk = {};
    int* ram[10][10] = {{0}};
    int* regs[5] = {0};
} cpu1;

#define Start_Value 16

#define DEF_CMD(name, num, arg, codd)                                                                       \
    case num:                                                                                               \
        codd                                                                                                \
        ip+=1;                                                                                              \
        break;


int main() {

    FILE *input = NULL;
    char fileinput [30] = "";

    fgets (fileinput, sizeof(fileinput), stdin);//origin.txt
    fileinput[strlen(fileinput) - 1] = '\0';
    input = fopen (fileinput, "rb");

    int size = 0;
    struct stat st = {0};
    stat (fileinput, &st);
    size = st.st_size;

    int* code = (int *) calloc (size, sizeof (int));
    fread (code, sizeof (int), size, input);

    StackCtor_ (&(cpu1.stk), Start_Value);

    printf ("%d\n", size);

    for (int i = 0; i < size/sizeof(int); i++) { printf ("%d\n", code[i]); }

    int ip = 0;

    while (ip < size) {

        switch (code[ip]) {

        //#include "cmd.h"

        }
    }

    return 0;
}
