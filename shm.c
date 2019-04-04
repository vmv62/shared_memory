#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include "shm.h"


//set shared memory with key
char *set_shmem(int id, int size)
{
	int shmid;
	key_t key;
	char *shm;

	key = (key_t)id;


	if ((shmid = shmget(key, size, IPC_CREAT | 0666)) < 0) {
		perror("shmget");
		return(1);
	}


	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		return(1);
	}


   return shm;
}

 
char *get_shmem(int id)
{
	int shmid;
	key_t key;
	char *shm, *s;

	key = (key_t)id;

	if ((shmid = shmget(key, SHMSZ, 0666)) < 0) {
		perror("shmget");
		return(1);
	}


	if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
		perror("shmat");
		return(1);
	}


    return	shm;
}
