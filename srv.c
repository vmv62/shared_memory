#include <stdio.h>
#include <string.h>
#include "shm.h"

int main(){

	typedef struct{
		char str1[64];
		char str2[64];
	}try_t;

	int *data;

	try_t dat;

	memcpy(dat.str1, "String 1\n", 9);
	memcpy(dat.str2, "String 2\n", 9);

	printf("Now we get shared memroy.\n");
	data = set_shmem(1234, sizeof(try_t));

	printf("Now we start coping data to shared memory.\n");
	memcpy(data, &dat, sizeof(dat));

	printf("Data is copied.c\n");

	while(1);;

	return 0;
}
