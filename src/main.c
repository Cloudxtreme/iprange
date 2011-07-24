#include <stdio.h>
#include "libiprange.h"

/* To shorten example, not using argp */
int main (int argc, char *argv[])
{
    printf("%s\n", iprange_version_string());

    if ( iprange_is_v4syntax(argv[1]) == 1 ) {
        printf("Cool, syntax of a real V4\n");
    }
    else {
        printf("Syntax check complained\n");
    }

    iprange_test(10, 127, 1000);
    return 0;
}
