FILES = shm.c
server:
	gcc shm.c srv.c -o srv


client:
	gcc shm.c cli.c -o cli

clean:
	rm cli srv
