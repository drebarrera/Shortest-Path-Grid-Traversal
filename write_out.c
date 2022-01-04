#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "write_out.h"
#include "struct.h"

void fastest_times(short m, short n, Gnode * graph[m+1][n], char * fptr, short * fx){
	fwrite(&n, sizeof(short),1,fptr);
	int min = graph[0][0] -> len;	
	for(int i = 0; i < n; i++){
		if(graph[0][i] -> len < min){
			min = graph[0][i] -> len;
			*fx = i;
		}
		fwrite(&(graph[0][i] -> len), sizeof(int),1,fptr);
	}

	return;
}

void fastest_path(short m, short n, Gnode * graph[m+1][n], char * fptr, short x, short y, int num){
	if(y != 0){
		int y_mod = y - 1;
		fwrite(&y_mod, sizeof(short),1,fptr);
		fwrite(&x, sizeof(short),1,fptr);
	}

	if(y == m){
		fseek(fptr, sizeof(int), SEEK_SET);
		fwrite(&num, sizeof(int),1,fptr);
		return;
	}
		
	if(graph[y][x] -> dir == 0)
		x--;
	else if(graph[y][x] -> dir == 1)
		x++;
	else if(graph[y][x] -> dir == 2)
		y--;
	else if(graph[y][x] -> dir == 3)
		y++;

	fastest_path(m, n, graph, fptr, x, y, num + 1);
		
	return;
}
