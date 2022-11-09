#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "oscargarcia.h"

void* threadfun(void *arg) {
    int thread_num = *((int *)arg);
    int i;

    printf("I’m the thread with id -> %d\n", thread_num);
    for(i=0;i<2;i++) {
        if (thread_num==1) {
            printf("O\n");
            sleep(1);
        } else {
            printf("o\n");
            sleep(2);
        }
    }
    pthread_exit(0);
}


int main() {
    printf("Hello world!\n");
    pthread_t thread1, thread2, thread3;
    int id1 = 1, id2 = 2;
    pthread_create(&thread1, NULL, threadfun, &id1);
    pthread_create(&thread2, NULL, threadfun, &id2);
    pthread_create(&thread3, NULL, my_own_thread_ogarcia, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    return 0;
}

