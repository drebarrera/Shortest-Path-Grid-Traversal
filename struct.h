#ifndef __STRUCT__
#define __STRUCT__

typedef struct _Gnode {
	int len;
	short dir; // 0 = left, 1 = right, 2 = up, 3 = down, 4 = stop node, 5 = unassigned
	short left;
	short right;
	short up;
	short down;
} Gnode;

#endif
