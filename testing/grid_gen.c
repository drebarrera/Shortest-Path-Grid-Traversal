#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void build(int x, short max, short min){
	char f[7];
	sprintf(f, "%d_%d.b",x,x);
	short val;
	FILE * fptr = fopen(f,"wb");

	
	
	
	fwrite(&x, sizeof(short), 1, fptr);
	fwrite(&x, sizeof(short), 1, fptr);
	for(int i = 0; i < x; i++){
		for(int j = 0; j < x; j++){
			val = (rand() % (max - min + 1)) + min;
			printf("val (%d, %d) -> %hd\n", i, j, val);
			fwrite(&val, sizeof(short), 1, fptr);
		}
	}
	printf("m = %hd, n = %hd\n", x, x);
	fclose(fptr);
}

void main(){
	short max;
	short min;
	printf("max -> ");
	scanf("%hd",&max);
	printf("min -> ");
	scanf("%hd",&min);
	for(int x = 1; x <= 20; x++){
		build(x, max, min);
	}
	for(int x = 3; x <= 20; x++){
		build(x*10, max, min);
	}
	for(int x = 3; x <= 10; x++){
		build(x*100, max, min);
	}
	for(int x = 2; x <= 10; x++){
		build(x*1000, max, min);
	}
	return;
}
