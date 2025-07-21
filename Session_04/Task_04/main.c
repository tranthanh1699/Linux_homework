#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h> 
#include <sys/types.h>
#include <stdbool.h>

long long counter = 0;
pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

void *write_thread_function(void *arg)
{   
    while (1)
    {
        // Protect the critical section with a write lock
        pthread_rwlock_wrlock(&rwlock);
        counter++;
        printf("Thread %ld is writing to counter %lld\n", pthread_self(), counter);
        pthread_rwlock_unlock(&rwlock);
        usleep(100); 
    }
    return NULL;
}

void *read_thread_function(void *arg)
{
    while (1)
    {
        long long local_counter;
        pthread_rwlock_rdlock(&rwlock);
        local_counter = counter;
        pthread_rwlock_unlock(&rwlock);
        printf("Thread %ld read counter: %lld\n", pthread_self(), local_counter);
        usleep(100);
    }
    
    return NULL;
}

int main()
{
    pthread_t write_thread_list[2]; 
    pthread_t read_thread_list[5]; 
    
    for (size_t i = 0; i < 2; i++)
    {
        pthread_create(&write_thread_list[i], NULL, write_thread_function, NULL);
    }

    for (size_t i = 0; i < 5; i++)
    {
        pthread_create(&read_thread_list[i], NULL, read_thread_function, NULL);
    }

    for (size_t i = 0; i < 2; i++)
    {
        pthread_join(write_thread_list[i], NULL);
    }

    for (size_t i = 0; i < 5; i++)
    {
        pthread_join(read_thread_list[i], NULL);
    }

    return 0;
}