#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    pid_t waitid;
    if (fork()== 0)
        exit(0);
    else
        waitid = wait(NULL);
    printf("Eltern PID = %d\n", getpid());
    printf("Kind PID = %d\n", waitid);

    return 0;
}