#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>   // for SYS_gettid
#include <sys/types.h>

long long counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
#define NUM_THREADS 3
void * increment_counter(void *arg) {
    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t thread_list[NUM_THREADS]; 
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&thread_list[i], NULL, increment_counter, NULL) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(thread_list[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }
    pthread_mutex_destroy(&mutex);
    printf("Final counter value: %lld\n", counter);
    return 0;
}