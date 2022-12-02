
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>
#include "getdata.h"



double GetG (const char* str);

double GetE ();

double GetT ();

double GetP ();

int    GetN ();



const char* s = NULL;




int main() {

    FILE *input = NULL;
    FILE *output = NULL;

    int size = 0;
    char *buf = NULL;

    getdata (&input, &output, &size, &buf);

    s = buf;

    double num = GetG (s);

    printf ("%f\n", num);

    return 0;
}




double GetG (const char* str) {

    S = str;

    double val = GetE();

    assert (*s == '\0');

    return val;
}



Node* GetE () {

    Node *val = GetT();

    Opcount = 0;

    Node *R = NULL;

    while (*S == '+' || *S == '-') {

        if (!Opcount) {

            val = NewOP (*S, L);

            S++;

            R = GetT();

            val -> right = R;



        }

        else {

            R = NewOP (*S, R);

            S++;

            R -> right = GetT();

            R = R -> right;

        }

        Opcount++;
    }

    return val;
}



Node* GetT () {

    Node* L = GetP();

    Node *R = NULL;

    while (*S == '*' || *S == '/') {

        Node *node = NewOP (*S);

        S++;

        R = GetP();

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



Node* GetN () {

    int val = 0;

    const char* sOLD = s;

    while ('0' <= *s && *s <= '9') {

        val = val*10 + *s - '0';

        s++;
    }

    assert (s > sOLD);

    return NewNum (val);
}
