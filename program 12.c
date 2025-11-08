#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];

void* philosopher(void* num) {
    int id = *(int*)num;
    sem_wait(&chopstick[id]);
    sem_wait(&chopstick[(id + 1) % 5]);
    printf("Philosopher %d is eating\n", id);
    sleep(1);
    printf("Philosopher %d is thinking\n", id);
    sem_post(&chopstick[id]);
    sem_post(&chopstick[(id + 1) % 5]);
    return NULL;
}

int main() {
    pthread_t philo[5];
    int i, id[5];
    for (i = 0; i < 5; i++) sem_init(&chopstick[i], 0, 1);
    for (i = 0; i < 5; i++) {
        id[i] = i;
        pthread_create(&philo[i], NULL, philosopher, &id[i]);
    }
    for (i = 0; i < 5; i++) pthread_join(philo[i], NULL);
    return 0;
}