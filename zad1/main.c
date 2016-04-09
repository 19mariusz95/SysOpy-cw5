#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <bits/signum.h>
#include <signal.h>

int get_N_arg(int argc, char *argv[]);

int main(int argc, char *argv[]) {

    int N = get_N_arg(argc, argv);
    char alina[100];
    sprintf(alina, "fold -w %d", N);


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
        execl("/bin/fold", alina, NULL);
    }
}

int get_N_arg(int argc, char *argv[]) {
    if (argc < 2) {
        printf("trolo");
        exit(1);
    }
    int result = atoi(argv[1]);
    if (result == 0) {
        printf("troloolo");
        exit(1);
    }
    return result;
}