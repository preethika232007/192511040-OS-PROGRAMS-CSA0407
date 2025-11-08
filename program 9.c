#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    int shmid;
    char *shm;
    key_t key = 5678;
    shmid = shmget(key, 1024, 0666|IPC_CREAT);
    shm = (char*) shmat(shmid, NULL, 0);
    strcpy(shm, "Hello from shared memory");
    printf("Data written: %s\n", shm);
    shmdt(shm);
    return 0;
}