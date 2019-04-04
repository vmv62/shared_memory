#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shm.h"


//set shared memory with key
int *set_shmem(int id, int size)
{
	int shmid;
	key_t key;
	int *shm;

	key = (key_t)id;

	printf("%d\n", size);
	printf("%d\n", key);

	if ((shmid = shmget(key, size, IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		exit(-1);
	}


	if ((shm = shmat(shmid, NULL, 0)) == (int *) -1) {
		perror("shmat");
		exit(-1);
	}

	printf("%d\n", shm);
   return *shm;
}

 
int *get_shmem(int id)
{
	int shmid;
	key_t key;
	int *shm;

	key = (key_t)id;

	if ((shmid = shmget(key, 100, 0666)) < 0) {
		perror("shmget");
		exit(-1);
	}


	if ((shm = shmat(shmid, NULL, 0)) == (int *) -1) {
		perror("shmat");
		exit(-1);
	}


    return	shm;
}
