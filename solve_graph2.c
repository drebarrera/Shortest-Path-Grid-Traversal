#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "solve_graph2.h"
#include "struct.h"

void solve_graph2(short m, short n, Gnode * graph[m+1][n]){
	short change = 1;
	int min = 0;
	int dir = 0;
	int iter = 0;
	while(change == 1){
		change = 0;
		iter++;
		for(int i = m-1; i > 0; i--){
			for(int j = 0; j < n; j++){
				if(graph[i][j] -> dir == 5){
					dir = 3;
					if(i == m-1)
						min = graph[i][j] -> down;
					else
						min = (graph[i][j] -> down) + (graph[i+1][j] -> len);
					change = 1;
				}
				else{
					min = graph[i][j] -> len;
					dir = graph[i][j] -> dir;
					if(i < m && (graph[i][j]-> down) + (graph[i+1][j] -> len) < min){
						min = (graph[i][j]-> down) + (graph[i+1][j] -> len);
						dir = 3;
						change = 1;
					}

					if(j > 0 && (graph[i][j]-> left) + (graph[i][j-1] -> len) < min){
						min = (graph[i][j]-> left) + (graph[i][j-1] -> len);
						dir = 0;
						change = 1;
					}
					
					if(j < n-1 && (graph[i][j]-> right) + (graph[i][j+1] -> len) < min){
						min = (graph[i][j]-> right) + (graph[i][j+1] -> len);
						dir = 1;
						change = 1;
					}

					if(i > 1 && (graph[i][j]-> up) + (graph[i-1][j] -> len) < min){
						min = (graph[i][j]-> up) + (graph[i-1][j] -> len);
						dir = 2;
						change = 1;
					}
				}
				graph[i][j] -> len = min;
				graph[i][j] -> dir = dir;
			}
		}
	}
	for(int i = 0; i < n; i++){
		graph[0][i] -> len = (graph[0][i] -> down) + (graph[1][i] -> len);
		graph[0][i] -> dir = 3;
	}
	return;
}
