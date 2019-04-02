#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	int shm;
	char *shm_ptr;
	key_t key = 135;

	if((shm = shmget(key, 0, 0)) < 0){
		perror("shm_client");
//		return(1);
	}

	shm_ptr = (char *)shmat(shm, NULL, 0);

	printf("%s", shm_ptr);

	return 0;
}
