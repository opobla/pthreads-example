#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* threadfun(void *arg) {
    int thread_num = *((int *)arg);
    printf("I’m the thread with id -> %d\n", thread_num);
    pthread_exit(0);
}


int main() {
    printf("Hello world!\n");
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;
    pthread_create(&thread1, NULL, threadfun, &id1);
    pthread_create(&thread2, NULL, threadfun, &id2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}

