


void getdata (FILE **input, FILE **output, int *size, char **buf);

int getsize (char* fileinput);

#define namelen 30





void getdata (FILE **input, FILE **output, int *size, char **buf) {

    char fileinput [namelen] = "";
    char fileoutput [namelen] = "";

    fgets (fileinput, sizeof(fileinput), stdin);
    fileinput[strlen(fileinput) - 1] = '\0';
    *input = fopen (fileinput, "rb");

    fgets (fileoutput, sizeof(fileoutput), stdin);
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
