#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

#define SHMSZ     27

int main()
{
    int c;
    int shmid;
    key_t key;
    int *shm, *s;
 
    key = 5678;
 
 
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        return(1);
    }
 
 
    if ((shm = shmat(shmid, NULL, 0)) == (int *) -1) {
        perror("shmat");
        return(1);
    }
 
    s = shm;
/*
    for (c = 48; c <= 80; c++)
        *s++ = c;
    *s = -1;
*/

	memcpy(s, "Hello\n", 6);

    while (*shm != '*')
        sleep(1);
 
    return(0);
}
