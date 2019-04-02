#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	int shm;
	char *shm_ptr;
	key_t key = 135;

	if((shm = shmget(key, 1000, IPC_CREAT | 0x0666)) < 0){
		perror("shmget");
//		shmdt(shm);
//		return(0);
	}

	shm_ptr = (char *)shmat(shm, NULL, 0);

	memcpy(shm_ptr, "Hello World!            \n", 13);

	while(1);;

	return 0;
}
