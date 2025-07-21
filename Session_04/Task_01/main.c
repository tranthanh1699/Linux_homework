#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/syscall.h>   // for SYS_gettid
#include <sys/types.h>

void * thread_function1(void *arg) {
    printf("Thread 1 is running with ID is: %lu\n", (unsigned long)pthread_self());
    return NULL;
}

void * thread_function2(void *arg) {
    printf("Thread 2 is running with ID is: %lu\n", (unsigned long)pthread_self());
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_function1, NULL);
    pthread_create(&thread2, NULL, thread_function2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}