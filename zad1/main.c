#include <stdio.h>
#include <stdlib.h>

int get_N_arg(int argc, char *argv[]);

int main(int argc, char *argv[]) {

    int N = get_N_arg(argc, argv);
    printf("%d\n", N);
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