#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <memory.h>
#include <zconf.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>

int wfd;

char *get_name(int argc, char **argv);

void handler(int sig) {
    close(wfd);
    exit(0);
}


int main(int argc, char *argv[]){

    char *name = get_name(argc, argv);

    wfd = open(name, O_WRONLY);

    if (wfd == -1) {
        printf("error while opening fifo");
        exit(1);
    }

    signal(SIGINT, handler);

    while (1) {
        char tmp[128];
        char tmp2[512];
        fgets(tmp, sizeof(tmp), stdin);
        time_t t = time(NULL);
        sprintf(tmp2, "%d - %li - %s", getpid(), t, tmp);
        write(wfd, tmp2, strlen(tmp2) + 1);
    }
}

char *get_name(int argc, char **argv) {
    if (argc < 2) {
        printf("You have to specify name of pipe as argument");
        exit(1);
    }
    return argv[1];
}