#include <stdio.h>

size_t strlength           (const char* cs);

char*  strcopy    (char* s, const char* cs);

char*  strchar             (const char* cs, char c);

char   strcomp             (const char* cs, const char* ct);

char*  strconcat  (char* s,                 const char* ct);



int main(void) {

    const char* cs = "abcd";

    printf ("%lu\n", (long unsigned) strlength (cs));




    char st[] = "MEOW";

    char* s = "MEOW"; //??? ?? ????? ???????? ??????? ?????? ?????????? s?

    printf ("st = <%s>\n", strcopy (st, cs));

    printf ("%p\n", strchar (cs, 'c')); // ????? ???????????? ????? ????????? %d ??? %p?

    printf ("%d\n", strcomp ("abb", "abc"));



    char st1[] = "BARK";

    char* s1 = st1;

    printf ("%s\n", strconcat (s1, "abc"));

    return 0;

}


size_t strlength (const char* cs) {

    int len = 0;

    while (cs[len] != '\0') {

        len++;
    }

    return len;

}


char* strcopy (char* s, const char* cs) {

    int i = 0;

    while (cs[i] != '\0') {

        s[i] = cs[i];

        i++;
    }

    s[i] = '\0';

    return s;
}


char* strchar (const char* cs, char c) {

    while (*cs != '\0') {

        if (*cs == c) return (char*) cs;

        cs++;
    }

    return NULL;
}


char strcomp (const char* cs, const char* ct) {

    int i = 0;

    bool equal = true;

    char res = 0;

    while (cs + i != '\0' && ct + i != '\0' && equal) {

        if (cs[i] < ct[i]) {

            equal = false;

            res = -1;

        }

        if (cs[i] > ct[i]) {

            equal = false;

            res = 1;

        }

        i++;

    }

    return res;
}


char* strconcat (char* s, const char* ct) {

    int i = 0;

    long long int len = strlength(s);

    while (ct[i] != '\0') {

        s[i + len] = ct[i];

        i++;
    }

    s[i + len] = '\0';

    return s;
}

