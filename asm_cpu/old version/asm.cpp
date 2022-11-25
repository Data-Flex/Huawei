#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "cmd.h"

enum {cmd_hlt = -1, cmd_out, cmd_push, cmd_pop, cmd_add, cmd_sup, cmd_mul, cmd_div, cmd_dump}

int process_buffer       (char* buf, int size);

char** generation_list   (char* buf, int size, int num_of_strings);



int main () {

    FILE *input = NULL;
    char fileinput [30] = "";

    FILE *output = NULL;
    char fileoutput [30] = "";

    int size = 0;

    fgets (fileinput, sizeof(fileinput), stdin);//origin.txt
    fileinput[strlen(fileinput) - 1] = '\0';
    input = fopen (fileinput, "r");

    fgets (fileoutput, sizeof(fileoutput), stdin);//asmres.txt
    fileoutput[strlen(fileoutput) - 1] = '\0';
    output = fopen (fileoutput, "w");

    struct stat st = {0};
    stat (fileinput, &st);
    size = st.st_size;

    char* buf = (char *) calloc ((size + 1), sizeof (char));
    fread (buf, sizeof (char), size, input);

    int num_of_strings = process_buffer (buf, size);

    char** text = generation_list (buf, size, num_of_strings);

    compile (text, num_of_strings, output);

    return 0;
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




