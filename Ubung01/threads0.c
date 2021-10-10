#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <threads.h>

//pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *args)

void *myThreadFun(void *args) {
    printf("This is Thread 1 at TID: %lu\n", thrd_current());
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_t thread_id2;
    printf("Main TID: %lu\n", thrd_current());
    pthread_create(&thread_id, NULL, myThreadFun, NULL);
    pthread_create(&thread_id2, NULL, myThreadFun, NULL);
    pthread_join(thread_id, NULL);
    pthread_join(thread_id2, NULL);
    if (pthread_equal(thread_id, thread_id2)) {
        printf("Threads have same ThreadID");
    } else {
        printf("Threads don't have the same ThreadID");
    }
    exit(0);
}