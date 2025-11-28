#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s [file1 name] ... \n", argv[0]);
        exit(0);
    }
    int num_files = argc - 1;
    int *fd_list = (int*)malloc(sizeof(int) * num_files);

    int open_count = 0;

    for (int i = 0; i < num_files; i++) {
        int fd = open(argv[i + 1], O_RDONLY);

        if (fd == -1) {
            perror(argv[i + 1]);
        } else {
            printf("opened success: %s (fd=%d)\n", argv[i + 1], fd);
            fd_list[open_count++] = fd;
        }
    }


    for (int i = 0; i < open_count; i++) {
        if (close(fd_list[i]) == -1) {
            perror("fail");
        }
    }


    free(fd_list);
    return 0;
}