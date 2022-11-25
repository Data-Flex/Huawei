

void compile (char** text, int num_of_strings, FILE *output);

void compile (char** text, int num_of_strings, FILE *output) {

    for (int line = 0; line < num_of_strings; line++) {

        char cmd[20] = "";

        int len = 0;

        sscanf (text[line], "%20s%n", cmd, &len);

        if (stricmp (cmd, "push") == 0) {

            int val = 0;

            sscanf (text[line] + len, "%d", &val);

            fprintf (output, "%d %d \n", cmd_push, val);
        }

        else if (stricmp (cmd, "pop") == 0)  fprintf (output, "%d \n", cmd_pop);

        else if (stricmp (cmd, "add") == 0)  fprintf (output, "%d \n", cmd_add);

        else if (stricmp (cmd, "sup") == 0)  fprintf (output, "%d \n", cmd_sup);

        else if (stricmp (cmd, "mul") == 0)  fprintf (output, "%d \n", cmd_mul);

        else if (stricmp (cmd, "div") == 0)  fprintf (output, "%d \n", cmd_div);

        else if (stricmp (cmd, "out") == 0)  fprintf (output, "%d \n", cmd_out);

        else if (stricmp (cmd, "dump") == 0) fprintf (output, "%d \n", cmd_dump);

        else if (stricmp (cmd, "hlt") == 0)  fprintf (output, "%d \n", cmd_hlt);

    }
}
