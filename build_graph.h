#ifndef __BUILD_GRAPH_H
#define __BUILD_GRAPH_H
#include <stdbool.h>
#include "struct.h"

Gnode * construct_node(short left, short right, short up, short down);

void build_graph(short m, short n, short grid[m][n], Gnode * graph[m+1][n]);

void free_graph(short m, short n, Gnode * graph[m+1][n]);

#endif
