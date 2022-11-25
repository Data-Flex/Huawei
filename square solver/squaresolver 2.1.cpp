#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001


void square             (double  a, double  b, double  c, int* rootcount, double* x1, double* x2);

void lineal                        (double  b, double  c, int* rootcount, double* x1);

void simple                                   (double  c, int* rootcount);

void printans           (double  a, double  b, double  c, int  rootcount, double  x1, double  x2, int ref_rootcount, double ref_x1, double ref_x2);

void solve              (double  a, double  b, double  c, int* rootcount, double* x1, double* x2);

void print_solve_result                                  (int  rootcount, double  x1, double  x2);

void print_info                                          (int  rootcount, double  x1, double  x2);

void operate_one_string (FILE *fsquare, int* check_not_EOF);

bool equal_double (double num1, double num2);



int main(void) {


    FILE *fsquare = NULL;
    char filename [30] {};


    if (*gets(filename) == NULL) printf ("Wrong name of file\n");

    else {

        fsquare = fopen (filename, "r"); //coefficients for square.txt


        int check_not_EOF = NAN;


        operate_one_string (fsquare, &check_not_EOF);


        while(check_not_EOF != EOF) {

            operate_one_string (fsquare, &check_not_EOF);

        }

    }

    return 0;
}



void operate_one_string (FILE *fsquare, int* check_not_EOF) {


    double a = NAN, b = NAN, c = NAN, x1 = 0, x2 = 0, ref_x1 = 0, ref_x2 = 0;

    int rootcount = -1, ref_rootcount = -2;


    if (fscanf (fsquare, "%lg %lg %lg", &a, &b, &c) == 3) {

        solve (a, b, c, &rootcount, &x1, &x2);

        if ((*check_not_EOF = getc (fsquare)) == ' ') {

            fscanf (fsquare, "%d", &ref_rootcount);

            if (ref_rootcount == 1) fscanf (fsquare, "%lg",     &ref_x1);

            if (ref_rootcount == 2) fscanf (fsquare, "%lg %lg", &ref_x1, &ref_x2);

        }

    }


    printans (a, b, c, rootcount, x1, x2, ref_rootcount, ref_x1, ref_x2);


    while (*check_not_EOF != '\n' && *check_not_EOF != EOF ) {

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



void printans (double a, double b, double c, int rootcount, double x1, double x2, int ref_rootcount, double ref_x1, double ref_x2)  {


    if (ref_rootcount == -2) {

        print_solve_result (rootcount, x1, x2);

    }

    else if (rootcount == ref_rootcount && equal_double (x1, ref_x1) && equal_double (x2, ref_x2)) printf ("\nSuccess \n");

    else {

            printf ("\nError with test.\n");

            printf ("True "); print_info (ref_rootcount, ref_x1, ref_x2);

            printf ("  My "); print_info (    rootcount,     x1,     x2);

            printf ("Arguments are %lg %lg %lg \n", a, b, c);

            printf ("%lg %lg %lg %lg %lg %lg\n", rootcount, x1, x2, ref_rootcount, ref_x1, ref_x2);

        }
}



bool equal_double (double num1, double num2) {

    return fabs (num1 - num2) < EPSILON;
}



void print_solve_result (int rootcount, double x1, double x2) {

    if (rootcount == -1) printf("\nError with coefficients: they are not numbers\n");

    if (rootcount == 0)  printf("\nThe equation has no roots\n");

    if (rootcount == 1)  printf("\nThe equation has 1 root: x = %lg\n", x1);

    if (rootcount == 2)  printf("\nThe equation has 2 roots: x1 = %lg and x2 = %lg\n", x1, x2);

    if (rootcount == 3)  printf("\nThe equation has an infinite number of roots\n");
}



void print_info (int rootcount, double x1, double x2) {

    if (rootcount == 0) printf ("answer: the equation has no roots\n");

    if (rootcount == 1) printf ("answer: the equation has 1 root: x = %lg\n", x1);

    if (rootcount == 2) printf ("answer: the equation has 2 roots: x1 = %lg and x2 = %lg\n", x1, x2);

    if (rootcount == 3) printf ("answer: the equation has an infinite number of roots\n");

}








