
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


//struck asm {
//
//    int* code;
//
//}

int  compile (char** text, int num_of_strings, int* code);

void GetArgs (char* argptr, int* code, int* ip);

int process_buffer       (char* buf, int size);

char** generation_list   (char* buf, int size, int num_of_strings);

void getdata (FILE **input, FILE **output, int *size, char **buf);

int getsize (char* fileinput);

#define namelen 30
#define cmdlen 20


#define DEF_CMD(name, num, arg, codd)                                                           \
    if (stricmp(cmd,#name) == 0) {                                                              \
        code[ip] = num;                                                                         \
        ip += 1;                                                                                \
        if (arg) GetArgs(text[line] + len, code, &ip);                                          \
    }                                                                                           \
    else



int main() {

    FILE *input = NULL;
    FILE *output = NULL;

    int size = 0;
    char *buf = NULL;

    getdata (&input, &output, &size, &buf);


    int num_of_strings = process_buffer (buf, size);


    char** text = generation_list (buf, size, num_of_strings);


    int* code = (int *) calloc ((2*num_of_strings), sizeof (int));


    int ip = compile (text, num_of_strings, code);


    for (int i = 0; i < ip; i++) printf ("%d ", code[i]);


    fwrite (code, sizeof(int), ip, output);


    return 0;
}



int compile (char** text, int num_of_strings, int* code) {

    int ip = 0;

    for (int line = 0; line < num_of_strings; line++) {

        //check for labels or

        char cmd[20] = "";

        int len = 0;

        sscanf (text[line], /*"%" TEXT(BUFSIZE) "s%n"*/ "%20s%n", cmd, &len);

        printf ("%s\n", cmd);

        #include "cmd.h"

        /* else */ printf ("ERROR ");

    }

    return ip;

}



void GetArgs(char* argptr, int* code, int* ip) {

    int val = 0;

    sscanf (argptr, "%d", &val);

    code[*ip] = val;

    *ip+=1;

}



int process_buffer (char* buf, int size) {

    int num_of_strings = 0;

    for (int i = 0; i < size; i++) {

        if (*(buf + i) == '\n') {

            *(buf + i) =  '\0';

            num_of_strings ++;
        }
    }

    num_of_strings ++;

    *(buf + size + 1) = '\0';

    return num_of_strings;
}



char** generation_list (char* buf, int size, int num_of_strings) {

    int j = 0;

    char** text  = (char **) calloc (num_of_strings, sizeof (char *));

    text[j] = buf;

    for (int i = 0; i < size; i++) {

        if (*(buf + i) == '\0') {

            j++;

            text[j] = buf + i + 1;
        }
    }

    return text;
}



void getdata (FILE **input, FILE **output, int *size, char **buf) {

    char fileinput [namelen] = "";
    char fileoutput [namelen] = "";

    fgets (fileinput, sizeof(fileinput), stdin);//origin.txt
    fileinput[strlen(fileinput) - 1] = '\0';
    *input = fopen (fileinput, "rb");

    fgets (fileoutput, sizeof(fileoutput), stdin);//asmres.txt
    fileoutput[strlen(fileoutput) - 1] = '\0';
    *output = fopen (fileoutput, "wb");

    *size = getsize (fileinput);

    *buf = (char *) calloc ((*size + 1), sizeof (char));
    fread (*buf, sizeof (char), *size, *input);
}



int getsize (char* fileinput) {

    struct stat st = {0};

    stat (fileinput, &st);

    return st.st_size;
}

