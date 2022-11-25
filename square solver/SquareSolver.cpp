#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001


void square             (double  a, double  b, double  c, int* rootcount, double* x1, double* x2);

void lineal                        (double  b, double  c, int* rootcount, double* x1);

void simple                                   (double  c, int* rootcount);

void printans                                            (int  rootcount, double  x1, double  x2);

void solve              (double  a, double  b, double  c, int* rootcount, double* x1, double* x2);

void operate_one_string (double* a, double* b, double* c, int* rootcount, double* x1, double* x2, FILE *fsquare, int* check_not_EOF);

bool equal_double (double num1, double num2);



int main(void) {


    FILE *fsquare = NULL;
    char filename [30] {};


    if (*gets(filename) == NULL) printf ("Wrong name of file\n");

    else {

        fsquare = fopen (filename, "r"); //coefficients for square.txt


        double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
        int rootcount = -1, check_not_EOF = NAN;


        operate_one_string (&a, &b, &c, &rootcount, &x1, &x2, fsquare, &check_not_EOF);


        while(check_not_EOF != EOF) {


            rootcount = -1;


            operate_one_string (&a, &b, &c, &rootcount, &x1, &x2, fsquare, &check_not_EOF);


        }

    }

    return 0;
}



void operate_one_string (double* a, double* b, double* c, int* rootcount, double* x1, double* x2, FILE *fsquare, int* check_not_EOF) {


    if (fscanf (fsquare, "%lg %lg %lg", a, b, c) == 3) {

        solve (*a, *b, *c, rootcount, x1, x2);

    }


    printans (*rootcount, *x1, *x2);


    *check_not_EOF = getc (fsquare);


    while (*check_not_EOF != '\n' && *check_not_EOF != EOF && *check_not_EOF != '/') {

        *check_not_EOF = getc (fsquare);

    }


}



void solve(double a, double b, double c, int* rootcount, double* x1, double* x2)  {


    if (equal_double (a, 0)) {


        if (equal_double (b, 0)) simple       (c, rootcount);


        else                     lineal    (b, c, rootcount, x1);

    }


    else                         square (a, b, c, rootcount, x1, x2);

}



void lineal(double b, double c, int* rootcount, double* x1)  {

    if (equal_double (c, 0)) *x1 =  c/b;

    else                     *x1 = -c/b;

    *rootcount = 1;
}



void square (double a, double b, double c, int* rootcount, double* x1, double* x2) {


    double d = b*b - 4*a*c;


    if (d < 0) *rootcount = 0;


    if (equal_double (d, 0)) {

            *rootcount = 1;

            *x1 = (-b) / (2*a);
    }


    if (d > 0) {

            *rootcount = 2;

            *x1 = (-b - sqrt(d)) / (2*a);

            *x2 = (-b + sqrt(d)) / (2*a);
    }
}



void simple (double c, int* rootcount)  {

    if (equal_double (c, 0)) *rootcount = 3;   //This equation has an infinite number of roots

    else                     *rootcount = 0;   //This equation has no root
}



void printans (int rootcount, double x1, double x2)  {


    if (rootcount == -1) printf("\n Error with coefficients: they are not numbers\n");


    if (rootcount == 0)  printf("\n The equation has no roots\n");


    if (rootcount == 1)  printf("\n The equation has 1 root: x = %lg\n", x1);


    if (rootcount == 2)  printf("\n The equation has 2 roots: x1 = %lg and x2 = %lg\n", x1, x2);


    if (rootcount == 3)  printf("\n The equation has an infinite number of roots\n");
}


bool equal_double (double num1, double num2) {

    return fabs (num1 - num2) < EPSILON;
}
