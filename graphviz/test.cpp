#include <stdio.h>
#include <TXlib.h>

int main() {

    system("dot list.txt -T png -o res.gv");

    return 0;
}
