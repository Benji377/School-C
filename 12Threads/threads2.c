#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <threads.h>

//pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *args)

void *myThreadFun(void *args) {
    //sleep(1);
    int num = (int) args;
    printf("Thread at TID: %lu\n", thrd_current());
    return (void *) (num * num);
}

int main() {
    pthread_t thread_id;
    int x_num = 10;
    int ergebnis;
    printf("Main at TID: %lu\n", thrd_current());
    pthread_create(&thread_id, NULL, myThreadFun, (void *) x_num);
    pthread_join(thread_id, (void *)&ergebnis);
    printf("Ergebniss: %i", ergebnis);
    exit(0);
}