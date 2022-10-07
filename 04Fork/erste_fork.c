#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char ** argv) {
    pid_t waitpid;
    printf ("Eltern PID = %d\n", getpid());
    erg = fork();
    if (erg == -1) {
        perror("Fork hat nicht funktioniert");
        exit(-1);
    }

    if (atoi(argv[2]) < atoi(argv[1])) {
        sleep(atoi(argv[2]));
    } else {
        wait(NULL);
        sleep(atoi(argv[2]) - atoi(argv[1]));
    }
    printf("Ende Eltern");


    if (fork() == 0) {
        printf ("Kind PID = %d\n", getpid());
        sleep(1);
    } else {
        waitpid = wait(NULL);
        printf ("Eltern PID = %d\n",getpid());
        printf("Kind PID = %d\n", waitpid);
        sleep(1);
    }
    return 0;
}