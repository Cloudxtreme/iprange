#include <stdio.h>
#include <string.h>
#include "libconfig.h"

#define LEN 64

/*
 * TODO
 * As long as we don't oblige clients to these functions to pass
 * buffers for writing config/version details to, we should probably
 * statically declare one buffer per function in here.
 *
 */
static char buf[LEN];

char *iprange_version_string()
{
    sprintf(buf, "%d.%d", LIB_VERSION_MAJOR, LIB_VERSION_MINOR);
    return buf;
}
