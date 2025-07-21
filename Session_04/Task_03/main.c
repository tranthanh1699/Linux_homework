#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h> 
#include <sys/types.h>
#include <stdbool.h>

static int data = 0; 
static bool data_ready = false;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void * producer(void *arg) {
    for(int i = 0; i < 10; i++) {
        pthread_mutex_lock(&mutex);
        data = rand(); 
        data_ready = true; // Indicate that data is ready
        pthread_cond_signal(&cond); // Notify consumer
        pthread_mutex_unlock(&mutex);
        sleep(2); // Simulate time taken to produce data
    }
    return NULL;
}

void * consumer(void *arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (!data_ready) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("Consumed data recv: %d\n", data);
        data_ready = false;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t prod, cons; 

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0; 
}