#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 128

int main(int argc, char *argv[]) {

    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }

    char *readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;

    while (1) {
        read_result = read(STDIN_FILENO, readStr, BUF_SIZE);

        if (read_result < 0) {
            perror("read");
            free(readStr);
            exit(1);
        }

        if (read_result == 0) {
            write(STDOUT_FILENO, "Detected EOF (Ctrk + D)\n", strlen("Detected EOF (Ctrk + D)\n"));
            write(STDOUT_FILENO, "Terminating read loop ...\n", strlen("Terminating read loop ...\n"));
            break;
        }

        int written = 0;
        while (written < read_result) {
            int w = write(STDOUT_FILENO, readStr + written, read_result - written);
            if (w < 0) {
                perror("write");
                free(readStr);
                exit(1);
            }
            written += w;
        }
    }

    free(readStr);
    return 0;
}