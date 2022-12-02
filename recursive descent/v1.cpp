
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>

void getdata (FILE **input, FILE **output, int *size, char **buf);

int getsize (char* fileinput);

double GetG (const char* str);

double GetE ();

double GetT ();

double GetP ();

int    GetN ();



const char* s = NULL;
#define namelen 30



int main() {

    FILE *input = NULL;
    FILE *output = NULL;

    int size = 0;
    char *buf = NULL;

    getdata (&input, &output, &size, &buf);

    s = buf;

    for (int i = 0; i < size; i++) printf("%d ", buf[i]);

    printf ("\n");

    double num = GetG (s);

    printf ("%f\n", num);

    return 0;
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



double GetG (const char* str) {

    s = str;

    double val = GetE();

    assert (*s == '\0');

    return val;
}



double GetE () {

    double val = GetT();

    while (*s == '+' || *s == '-') {

        char op = *s;

        s++;

        double val2 = GetT();

        if (op == '+') val += val2;

        else           val -= val2;
    }

    return val;
}



double GetT () {

    double val = GetP();

    while (*s == '*' || *s == '/') {

        char op = *s;

        s++;

        double val2 = GetP();

        if (op == '*') val *= val2;

        else           val /= val2;
    }

    return val;
}



double GetP () {

    double val = 0;

    if (*s == '(') {

        s++;

        val = GetE();

        assert (*s == ')');

        s++;
    }

    else val = (double) GetN();

    return val;
}



int GetN () {

    int val = 0;

    const char* sOLD = s;

    while ('0' <= *s && *s <= '9') {

        val = val*10 + *s - '0';

        s++;
    }

    assert (s > sOLD);

    return val;
}
