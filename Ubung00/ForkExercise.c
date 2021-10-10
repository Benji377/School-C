#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    pid_t fff = fork();
    if (fff == 0) {
        printf("I am child\n");
        printf("My ID: %i\n", getpid());
        printf("Parent ID: %i\n", getppid());
        waitpid(getpid());
    } else {
        printf("I am parent\n");
        printf("My ID: %i\n", getpid());
        printf("Parent ID: %i\n", getppid());
    }
    return 0;
}
