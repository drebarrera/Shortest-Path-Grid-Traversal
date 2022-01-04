#ifndef __WRITE_OUT_H__
#define __WRITE_OUT_H__
#include <stdbool.h>
#include "struct.h"

void fastest_times(short m, short n, Gnode * graph[m+1][n], char * fptr, short * fx);

void fastest_path(short m, short n, Gnode * graph[m+1][n], char * fptr, short x, short y, int num);

#endif
