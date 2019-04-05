#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "shm.h"

int main(){

	typedef struct{
		char str1[64];
		char str2[64];
		int numb;
	}try_t;

	try_t *data;

	try_t dat;

	strcpy(dat.str1, "String 1\n");
	strcpy(dat.str2, "String 2\n");

	data = (try_t *)set_shmem(SHM_KEY, sizeof(try_t));


	while(1){
		data->numb++;
		sleep(1);
	}

	return 0;
}
