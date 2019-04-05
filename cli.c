#include <stdio.h>
#include <string.h>
#include "shm.h"

int main(){
	typedef struct{
		char str1[64];
		char str2[64];
	}try_t;

	try_t *data;

	data = get_shmem(1234);

	printf("%s", data->str1);
	printf("%s", data->str2);

	return 0;
}
