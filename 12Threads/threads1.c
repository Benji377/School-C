#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <threads.h>

//pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *args)

void *myThreadFun(void *args) {
    //sleep(1);
    int num = 10;
    printf("Thread at TID: %lu\n", thrd_current());
    for (int i = num; i >= 0; i--) {
        printf("%i.\n", i);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    printf("Main at TID: %lu\n", thrd_current());
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    exit(0);
}