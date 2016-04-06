#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <zconf.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

char *get_name(int argc, char **argv);

int main(int argc, char *argv[]) {

    char *name = get_name(argc, argv);

    char ala[512];
    char ala2[1024];

    mkfifo(name, S_IRWXU);
    int rfd = open(name, O_RDONLY);

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
        printf("trololo");
        exit(1);
    }
    return argv[1];
}