#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "write_grid.h"
#include "struct.h"

void get_mn(char * fptr, short * m, short * n){
	fseek(fptr, 0, SEEK_SET);
	fread(m,sizeof(short),1,fptr);
	fread(n,sizeof(short),1,fptr);
	
	return;
}

void read_write_grid(char * fr, char * fwptr, short * grid_item){
	fread(grid_item,sizeof(short),1,fr);
	fprintf(fwptr, "%hd", *grid_item);
	return;
}
