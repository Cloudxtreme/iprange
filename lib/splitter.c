/*
 * Make this the first file to follow GNU coding standards for
 * formatting C as closely as possible.
 */

#include <stdlib.h>
#include <string.h>

/* freakishly: */
#include <stdio.h>

/* put _no code_ in here that needs not see R and U */
static unsigned int R, U;
static char buf[sizeof(int)*8 + 1];

static unsigned int
_pow(const unsigned int b, unsigned int e)
{
    if ( e == 0 ) return 1;
    else          return b * _pow(b, --e);
}

static unsigned int
_raise(unsigned int i)
{
    unsigned int j, n, u;
    /* find u a little lower than U */
    sprintf(buf, "%u", U); j = strlen(buf);
    for ( ; j > 0; j-- ) if ( U-i > _pow(R, j) ) break;
    u = U / _pow(R, j) * _pow(R, j);
    /* calc n as explained below */
    if ( i == 0 ) n = R - 1; // Safeguard
    else {
        j = 1;
        for ( ; (i % R) == 0; j++ ) i = i/R; // Rshift while rightmost==0
        n = (R+i) / R * _pow(R, j) - 1; // Up by R, round, lshift back
                                        // and subtract 1
    } // Return a candidate guaranteed not to exceed U
    if ( n < u ) return n;
    else         return ( u == U ) ? U : u - 1;
}

void
iprange_test(const unsigned int r, const unsigned int L, const unsigned int u)
{
    unsigned int z;
    R = r; U = u;

    sprintf(buf, "%u", L); printf("%s", buf);
    z = _raise(L);
    while ( z < U ) {
        sprintf(buf, "%u", z);     printf("..%s\n", buf);
        sprintf(buf, "%u", z + 1); printf("%s",     buf);
        z = _raise(++z);
    }
    sprintf(buf, "%u", z); printf("..%s\n", buf);
}
