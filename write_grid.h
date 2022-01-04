#ifndef __WRITE_GRID_H__
#define __WRITE_GRID_H__
#include <stdbool.h>
#include "struct.h"

void get_mn(char * fptr, short * m, short * n);

void read_write_grid(char * fr, char * fwptr, short * grid_item);

#endif
