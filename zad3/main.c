#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *get_output(int argc, char **argv);

void execute(char *papiez);

int main(int argc, char *argv[]) {

    char *alina = get_output(argc, argv);
    char *ala = "ls -l | grep ^d > ";
    size_t size = strlen(alina) + strlen(ala) + 1;
    char papiez[size];
    papiez[size - 1] = '\0';
    strcpy(papiez, ala);
    strcpy(papiez + strlen(ala), alina);
    execute(papiez);
}

void execute(char *papiez) {
    FILE *cmd = popen(papiez, "r");
    if (cmd == NULL) {
        printf("trololoo");
        exit(1);
    }
}

char *get_output(int argc, char **argv) {
    if (argc < 2) {
        printf("trololo");
        exit(1);
    }
    return argv[1];
}