#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t empty, full;
int buffer[10], in = 0, out = 0;

void* producer(void* arg) {
    int item = 1;
    sem_wait(&empty);
    buffer[in++] = item;
    sem_post(&full);
    return NULL;
}

void* consumer(void* arg) {
    sem_wait(&full);
    int item = buffer[out++];
    sem_post(&empty);
    return NULL;
}

int main() {
    pthread_t p, c;
    sem_init(&empty, 0, 10);
    sem_init(&full, 0, 0);
    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);
    pthread_join(p, NULL);
    pthread_join(c, NULL);
    return 0;
}