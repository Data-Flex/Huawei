
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>
#include "getdata.h"
#include "tree.h"
#include "graph.h"



Node* GetG (const char* str);

Node* GetE ();

Node* GetT ();

Node* GetP ();

Node* GetN ();

Node* Def (Node *root);


const char* S = NULL;
const char* Start = NULL;


int main() {

    FILE *input = NULL;
    FILE *output = NULL;

    int size = 0;
    char *buf = NULL;

    getdata (&input, &output, &size, &buf);

    S = buf; Start = buf;

    Node* root = GetG (S);

    Graph (root, output);

    fclose (input);
    fclose (output);

    system("dot output.txt -T png -o res.png");

    return 0;
}



//Node* Def (Node *root) {
//
//    Node *node = (Node *) calloc (1, sizeof (Node));
//
//    return node;
//}



Node* GetG (const char* str) {

    S = str;

    Node* val = GetE();

    if (*S != '\0') printf ("Syntax Error. Operator %c is unknown", *S);

    return val;
}



Node* GetE () {

    Node* L = GetT();

    Node* R = NULL;

    while (*S == '+' || *S == '-') {

        char Opname = *S;

        S++;

        R = GetT();

        L = NewOp (Opname, L, R);

    }

    return L;
}




Node* GetT () {

    Node* L = GetP();

    Node* R = NULL;

    while (*S == '*' || *S == '/') {

        char Opname = *S;

        S++;

        R = GetP();

        L = NewOp (Opname, L, R);
    }

    return L;
}




Node* GetP () {

    Node* val = NULL;

    if (*S == '(') {

        S++;

        val = GetE();

        if (*S != ')') printf ("Syntax Error. Operator ) is missed. Position: %d", (int) S - (int) Start + 1);

        S++;
    }

    else val = GetN();

    return val;
}




Node* GetN () {

    int val = 0;

    const char* SOLD = S;

    while ('0' <= *S && *S <= '9') {

        val = val*10 + *S - '0';

        S++;
    }

    if (S <= SOLD) printf ("Syntax Error. Position: %d", (int) S - (int) Start + 1);

    return NewNum (val);

}
