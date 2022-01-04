#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "write_grid.h"
#include "build_graph.h"
#include "solve_graph2.h"
#include "write_out.h"
#include "struct.h"

int main(int argc, char ** argv){
	
	// Check Arguments
	if (argc != 5)
		return EXIT_FAILURE;

	FILE * fptr = fopen(argv[1], "rb");
	if(fptr == NULL)
		return EXIT_FAILURE;
	
	short m;
	short n;
	get_mn(fptr, &m, &n);
	if(!m || !n)
		return EXIT_FAILURE;
	
	FILE * fwptr = fopen(argv[2], "w");
	fprintf(fwptr, "%hd %hd\n", m, n);
	short (*grid)[n] = malloc(m * n * sizeof(short));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			read_write_grid(fptr, fwptr, &grid[i][j]);
			if(j != n - 1)
				fprintf(fwptr, " ");
		}
		fprintf(fwptr, "\n");
	}
	
	fclose(fptr);
	fclose(fwptr);
	
	Gnode * (*graph)[n] = malloc((m+1) * n * sizeof(Gnode*));
	build_graph(m, n, grid, graph);
	free(grid);

	solve_graph2(m, n, graph);

	short fastest_x = NULL;

	FILE * fptrW2 = fopen(argv[3], "wb");
	fastest_times(m, n, graph, fptrW2, &fastest_x);	
	fclose(fptrW2);
	
	FILE * fptrW3 = fopen(argv[4], "wb");
	fwrite(&(graph[0][fastest_x]->len), sizeof(int),1,fptrW3);
	int null_val = 0;
	fwrite(&null_val, sizeof(int),1,fptrW3);
	fastest_path(m, n, graph, fptrW3, fastest_x, 0, 0);	
	fclose(fptrW3);

	free_graph(m, n, graph);
	free(graph);

	return EXIT_SUCCESS;
}
