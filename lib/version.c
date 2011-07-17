#include <stdio.h>
#include <string.h>
#include "libconfig.h"

#define LEN 64

char buf[LEN];

char *iprange_version_string()
{
    sprintf(buf, "%d.%d", LIB_VERSION_MAJOR, LIB_VERSION_MINOR);
    return buf;
}

char *iprange_bollocks_string()
{
    return strncpy(buf, "bollocks", LEN);
}
