#include <stdio.h>
#include <unistd.h>

void* my_own_thread_ogarcia(void* args) {
    int i;

    printf("This is Oscar's thread\n");
    for (i=1; i<100; i++) {
        printf("Counting %d \n", i);
        usleep(100000);
    }

    return(0);
}
