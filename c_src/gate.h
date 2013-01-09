#ifndef GATE_H
#define GATE_H

#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

#define approxidate(s) approxidate_careful((s), NULL)
unsigned long approxidate_careful(const char *, int *);
unsigned long approxidate_relative(const char *date, const struct timeval *now);

enum date_mode {
	DATE_NORMAL = 0,
	DATE_RELATIVE,
	DATE_SHORT,
	DATE_LOCAL,
	DATE_ISO8601,
	DATE_RFC2822,
	DATE_RAW
};


#endif
