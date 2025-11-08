#include <stdio.h>
#include <pthread.h>

void* threadFunc(void* arg) {
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, threadFunc, NULL);
    pthread_create(&t2, NULL, threadFunc, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    if (pthread_equal(t1, t2)) {
        printf("Threads are equal\n");
    } else {
        printf("Threads are not equal\n");
    }
    return 0;
}