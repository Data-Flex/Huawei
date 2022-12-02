

void Graph (Node *node, FILE *output);

void Graph_tree (Node *node, FILE *output);




void Graph (Node *node, FILE *output) {

    fprintf (output, "digraph G\n");
    fprintf (output, "{\n");
    fprintf (output, "graph [dpi = 150];\n");

    Graph_tree (node, output);

    fprintf (output, "}\n");

}




void Graph_tree (Node *node, FILE *output) {


    if (node -> TYPE == num) fprintf (output, "%d[label = \"%d\"];\n", (int) node, node -> numvalue);

    else if (node -> TYPE == oper) fprintf (output, "%d[label = \"%c\"];\n", (int) node, (char) (node -> value));

    else if (node -> TYPE == var) fprintf (output, "%d[label = \"%c\"];\n", (int) node, node -> varvalue);

    if (node -> parent != NULL) fprintf (output, "%d->%d;\n", (int) (node -> parent), (int) node);

    if (node -> left != NULL)  Graph_tree (node -> left,  output);

    if (node -> right != NULL) Graph_tree (node -> right, output);

}

