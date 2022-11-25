#include <TXlib.h>
#include <stdio.h>
#include <string.h>


int main() {

    FILE *output = NULL;
    char fileoutput [30] = "";

    fgets (fileoutput, sizeof(fileoutput), stdin);//asmres.txt
    fileoutput[strlen(fileoutput) - 1] = '\0';
    output = fopen (fileoutput, "wb");

    int st[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a = 9;
    fwrite (st, sizeof(int), a, output);
}
