#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

enum type {num = 0, var = 1, oper = 2};

enum op {add = '+', sub = '-', mul = '*', divi = '/'};

struct TreeNode {

    enum type TYPE;

    double numvalue;
    char varvalue;
    enum op value;

    TreeNode *left = NULL;
    TreeNode *right = NULL;
    TreeNode *parent = NULL;
};


void getdata (FILE **input, FILE **output, int *size, char **buf);

int getsize (char *fileinput);

int process_buffer (char *buf, int size);

TreeNode* create_node (TreeNode *parentnode, TreeNode *node, char *newdata);

void fill_node_value (TreeNode *node, char *newdata);

TreeNode* readtree (char *buf, TreeNode *root, int *index);

#define varlen 123


double varlist[varlen] = {0};


#define startindex 0

#define namelen 30



char depth = 1;

int main() {

    FILE *input = NULL; //treedata.txt
    FILE *output = NULL;

    int size = 0;
    char *buf = NULL;

    getdata (&input, &output, &size, &buf);

    //int num_of_trees = process_buffer (buf, size);

    int index = startindex;

    TreeNode *root = NULL;

    root = readtree (buf, root, &index);

//    for (int i = 0; i < 15; i++) {
//
//        printf ("%d ", buf[i]);
//    }

    printf ("%g %c %g", root->left->numvalue, root->value, root->right->numvalue);

    return 0;
}



void getdata (FILE **input, FILE **output, int *size, char **buf) {

    char fileinput [namelen] = "";
    char fileoutput [namelen] = "";

    fgets (fileinput, sizeof(fileinput), stdin);//origin.txt
    fileinput[strlen(fileinput) - 1] = '\0';
    *input = fopen (fileinput, "r");

    fgets (fileoutput, sizeof(fileoutput), stdin);//asmres.txt
    fileoutput[strlen(fileoutput) - 1] = '\0';
    *output = fopen (fileoutput, "w");

    *size = getsize (fileinput);

    *buf = (char *) calloc ((*size + 1), sizeof (char));
    fread (*buf, sizeof (char), *size, *input);
}



int getsize (char* fileinput) {

    struct stat st = {0};

    stat (fileinput, &st);

    return st.st_size;
}



int process_buffer (char* buf, int size) {

    int num_of_trees = 0;

    bool treedata = false;

    for (int i = 0; i < size; i++) {

        if (*(buf + i) == '\"' && !treedata) treedata = true;

        else if (*(buf + i) == '\"') {

            *(buf + i) = '\0';

            num_of_trees++;

            treedata = false;
        }

    }

    return num_of_trees;
}



TreeNode* create_node (TreeNode *parentnode, TreeNode *node, char *newdata) {

    //TreeNode *node = (TreeNode *) calloc (1, sizeof (TreeNode));

    fill_node_value (node, newdata);

    if (parentnode != NULL) {

        if (parentnode -> left == NULL) {

            parentnode -> left = node;

            node -> parent = parentnode;
        }

        else if (parentnode -> right == NULL) {

            parentnode -> right = node;

            node -> parent = parentnode;
        }

        else printf("Error with creation of node. Both left and right aren't NULL.\n");
    }

    return node;
}



void fill_node_value (TreeNode *node, char *newdata) {

    if (*newdata <= 'z' && *newdata >= 'a') {

        node -> TYPE = var;

        node -> varvalue = *newdata;

        //printf ("var \n");
    }

    else if (*newdata == '+' || *newdata == '-' || *newdata == '*' || *newdata == '/') {

        node -> TYPE = oper;

//        if (*newdata == '+') node -> value = add;
//
//        else if (*newdata == '-') node -> value = sub;
//
//        else if (*newdata == '*') node -> value = mul;
//
//        else if (*newdata == '/') node -> value = divi;

        node -> value = (op) *newdata;
    }

    else if (*newdata <= '9' && *newdata >= '0') {

        node -> TYPE = num;

        sscanf (newdata, "%lf", &(node -> numvalue));

        //printf ("num \n");
    }

    else printf ("Error with creation of node. Inputed value is not operable\n");
}



TreeNode* readtree (char *buf, TreeNode *root, int *index) {

    TreeNode *node = (TreeNode *) calloc (1, sizeof (TreeNode));

    (*index)++;


    if (buf[*index] == '(') {

        readtree (buf, node, index);

        (*index) += 2;
    }


    node = create_node (root, node, buf + *index);



    double trash = 0;
    int len = 0;

    sscanf (buf + *index, "%lf%n", &trash, &len);

    if (len) (*index) += len - 1;




    if (buf[*index + 2] == '(') {

        (*index) += 2;

        readtree (buf, node, index);
    }


    (*index)++;

    return node;
}
