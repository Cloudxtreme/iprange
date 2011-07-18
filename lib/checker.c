/*
 * Has code for checking the syntactical correctness of IP addresses.
 */

#include <stdio.h>
#include <sys/types.h>
#include <regex.h>

#define V4REGEX "^(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3,3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$"

int iprange_is_v4syntax(const char *ip)
{
    int         status;
    regex_t     re;
    regmatch_t  zero[0];
    
    if ( regcomp(&re, V4REGEX, REG_EXTENDED|REG_NOSUB) != 0 ) {
        return -1;      /* report error */
    }
    status = regexec(&re, ip, (size_t) 0, zero, 0);
    regfree(&re);
    if ( status == REG_NOMATCH ) {
        return 0;       /* report no matches */
    }
    else {
        return 1;
    }
}

int iprange_is_v6syntax(const char *ip)
{
    /* not implemented */
    return -1;
}
