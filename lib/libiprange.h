/*
 * Contains functions for public access in libiprange.a and libiprange.so
 *
 * File: libiprange.h
 */

extern void
iprange_test(const unsigned int, const unsigned int, const unsigned int);

extern int
iprange_is_v4syntax(const char *);

/*
/// \return LIB_VERSION_MAJOR . LIB_VERSION_MINOR from cmake configuration
 */
extern char *
iprange_version_string();
