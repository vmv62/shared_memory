#include <stdio.h>
#include <string.h>
#include "shm.h"

int main(){
	typedef struct{
		char str1[64];
		char str2[64];
		int numb;
	}try_t;

	try_t *data;

	data = (try_t *)get_shmem(SHM_KEY, SHMSZ);
/*
	printf("%s", data->str1);
	printf("%s", data->str2);
*/
	printf("%d\n", data->numb);

	return 0;
}
