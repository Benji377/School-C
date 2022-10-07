#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
// x = (3 + 1) * (6 – 4)

int main() {
    int fd1[2];
    int fd2[2];

    int n1 = 3;
    int n2 = 1;
    int n3 = 6;
    int n4 = 4;

    pid_t foork = fork();

    if (foork == 0) {
        // Child
        int sum = n3 - n4;
        printf("RES1: %i\n", sum);
    } else {
        int sum = n1 + n2;
        printf("RES2: %i\n", sum);
    }
}