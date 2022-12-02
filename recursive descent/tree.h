


enum type {empty = -1, num = 0, var = 1, oper = 2};

enum op {add = '+', sub = '-', mul = '*', divi = '/'};

struct Node {

    enum type TYPE = empty;

    int numvalue;
    char varvalue;
    enum op value;

    Node *left = NULL;
    Node *right = NULL;
    Node *parent = NULL;
};




Node* NewNum (int newdata);

Node* NewOp  (char Opname, Node* L, Node* R);




Node* NewNum (int newdata) {

    Node *node = (Node *) calloc (1, sizeof (Node));

    node -> TYPE = num;

    node -> numvalue = newdata;

    return node;

}


Node* NewOp (char Opname, Node* L, Node* R) {

    Node *node = (Node *) calloc (1, sizeof (Node));

    node -> TYPE = oper;

    node -> value = (op) Opname;

    node -> left = L;
    L -> parent = node;

    node -> right = R;
    R -> parent = node;

    return node;

}
