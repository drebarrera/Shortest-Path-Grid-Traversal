#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "build_graph.h"
#include "struct.h"

Gnode * construct_node(short left, short right, short up, short down){
	Gnode * node = malloc(sizeof(*node));
	node -> len = NULL;
	node -> left = left;
	node -> right = right;
	node -> up = up;
	node -> down = down;
	node -> dir = 5;
	return node;
}

void build_graph(short m, short n, short grid[m][n], Gnode * graph[m+1][n]){	
	// Start Cells
	for(int i = 0; i < n; i++){
		graph[0][i] = construct_node(0,0,0,grid[0][i]);
	}

	short left = 0;
	short right = 0;
	short up = 0;
	short down = 0;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(i == 0) // upper border cell
				up = 0;
			else
				up = grid[i-1][j];
			if(i == m-1) // bottom border cell
				down = 0;
			else
				down = grid[i+1][j];
			if(j == 0) // left border cell
				left = 0;
			else
				left = grid[i][j-1];
			if(j == n-1)
				right = 0;
			else
				right = grid[i][j+1];

			graph[i+1][j] = construct_node(left,right,up,down);
			
			if(i == m-1)
				graph[i+1][j] -> dir = 4;
		}
	}

	return;
}

void free_graph(short m, short n, Gnode * graph[m+1][n]){
	for(int i = 0; i <= m; i++){
		for(int j = 0; j < n; j++){
			free(graph[i][j]);
		}
	}

	return;
}

