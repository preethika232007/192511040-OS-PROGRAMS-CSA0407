#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex;

void* process(void* arg) {
    sem_wait(&mutex);
    printf("Process executing\n");
    sem_post(&mutex);
    return NULL;
}

int main() {
    pthread_t p1, p2;
    sem_init(&mutex, 0, 1);
    pthread_create(&p1, NULL, process, NULL);
    pthread_create(&p2, NULL, process, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    sem_destroy(&mutex);
    return 0;
}