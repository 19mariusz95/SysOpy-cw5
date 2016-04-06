#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <memory.h>
#include <zconf.h>

char *get_name(int argc, char **argv);


int main(int argc, char *argv[]){

    char *name = get_name(argc, argv);

    int wfd = open(name, O_WRONLY);

    while (1) {
        char tmp[1024];
        fgets(tmp, sizeof(tmp), stdin);
        write(wfd, tmp, strlen(tmp) + 1);
    }
}

char *get_name(int argc, char **argv) {
    if (argc < 2) {
        printf("trololo");
        exit(1);
    }
    return argv[1];
}