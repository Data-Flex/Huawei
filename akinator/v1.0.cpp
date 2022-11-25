#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

struct tree {

    char *data;
    tree *left;
    tree *right;
    tree *parent;
};


void getdata (FILE **input, FILE **output, int *size, char **buf);

int getsize (char* fileinput);

int process_buffer (char* buf, int size);

tree* create_node (tree *parentnode, char *newdata);

char* readtree (char *buf, tree *root);




#define namelen 30

char depth = 1;

int main() {

    FILE *input = NULL; //treedata.txt
    FILE *output = NULL;

    int size = 0;
    char *buf = NULL;

    getdata (&input, &output, &size, &buf);

    int num_of_trees = process_buffer (buf, size);

    tree *root = NULL;

    printf ("%d\n", num_of_trees);

    readtree (buf, root);

    printf()

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



tree* create_node (tree *parentnode, char *newdata) {

    tree *node = (tree *) calloc (1, sizeof (tree));

    node -> data = newdata;

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



char* readtree (char *buf, tree *root) {

    char *treedata = NULL;

    int i = 0;

    for (; *(buf + i) != '\0'; i++) {

        if (*(buf + i) == '\"') treedata = buf + i + 1;
    }


    //printf("%s\n", treedata);


    tree *node = create_node (root, treedata);

    if (*(buf + i + 1) == '}') return (buf + i + 3);

    else if (*(buf + i + 1) == '\n') {

        return (readtree (readtree ((buf + i + 2), node), node));
    }
}
