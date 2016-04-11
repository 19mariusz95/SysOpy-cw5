#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <zconf.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>

char *name;
int rfd;


char *get_name(int argc, char **argv);

void handler(int sig) {
    close(rfd);
    unlink(name);
    exit(0);
}

int main(int argc, char *argv[]) {

    name = get_name(argc, argv);

    char ala[512];
    char ala2[1024];

    if (mkfifo(name, S_IRWXU)) {
        printf("error while creating fifo");
        exit(1);
    }
    rfd = open(name, O_RDONLY);
    if (rfd == -1) {
        printf("error while opening fifo");
        exit(1);
    }

    signal(SIGINT, handler);

    while (1) {
        int tmp = read(rfd, ala, sizeof(ala));
        if (tmp > 0) {
            size_t t = time(NULL);
            sprintf(ala2, "%li - %s", t, ala);
            printf("%s", ala2);
        }
    }


}

char *get_name(int argc, char **argv) {
    if (argc < 2) {
        printf("You have to specify name of pipe as argument");
        exit(1);
    }
    return argv[1];
}