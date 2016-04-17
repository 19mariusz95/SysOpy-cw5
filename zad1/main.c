#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <bits/signum.h>
#include <signal.h>

int main(int argc, char *argv[]) {

    int okno[2];

    if (pipe(okno) < 0) {
        printf("error creating pipe");
        exit(1);
    }

    pid_t chodnik = fork();

    if (chodnik < 0) {
        printf("fork error");
        exit(1);
    }
    else if (chodnik > 0) {
        close(okno[0]);
        if (okno[1] != STDOUT_FILENO) {
            if (dup2(okno[1], STDOUT_FILENO) != STDOUT_FILENO) {
                printf("error");
                close(okno[1]);
                exit(2);
            }
        }
        execl("/bin/tr", "tr", "'[:lower:]'", "'[:upper:]'", NULL);
    } else {
        close(okno[1]);
        if (okno[0] != STDIN_FILENO) {
            if (dup2(okno[0], STDIN_FILENO) != STDIN_FILENO) {
                printf("error");
                close(okno[0]);
                exit(3);
            }
        }
        execlp("fold", "fold", "-w", argv[1], NULL);
    }
}

