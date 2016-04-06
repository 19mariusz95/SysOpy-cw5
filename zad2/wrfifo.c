#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <memory.h>
#include <zconf.h>
#include <sys/time.h>
#include <time.h>

char *get_name(int argc, char **argv);


int main(int argc, char *argv[]){

    char *name = get_name(argc, argv);

    int wfd = open(name, O_WRONLY);

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
        printf("trololo");
        exit(1);
    }
    return argv[1];
}