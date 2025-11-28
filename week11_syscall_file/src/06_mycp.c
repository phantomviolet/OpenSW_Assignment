#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 32

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage: %s [source file] [destination file1] [destination file2] ... \n", argv[0]);
        exit(0);
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("source file open fail");
        exit(0);
    }

    int num_files = argc - 2;
    int *dest_fd_list = (int*)malloc(sizeof(int) * num_files);
    for (int i = 0; i < num_files; i++) {
        dest_fd_list[i] = open(argv[i + 2],
                               O_WRONLY | O_CREAT | O_TRUNC,
                               S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
        if (dest_fd_list[i] == -1) {
            perror(argv[i + 2]);
            for (int j = 0; j < i; j++) {
                close(dest_fd_list[j]);
            }
            close(src_fd);
            free(dest_fd_list);
            exit(0);
        }
    }

    char *readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;
    while (1) {
        read_result = read(src_fd, readStr, BUF_SIZE);

        if (read_result < 0) {
            perror("read");
            break;
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
                perror("write stdout");
                break;
            }
            written += w;
        }

        for (int i = 0; i < num_files; i++) {
            int dst_written = 0;
            while (dst_written < read_result) {
                int w = write(dest_fd_list[i],
                              readStr + dst_written,
                              read_result - dst_written);
                if (w < 0) {
                    perror("write dest");
                    break;
                }
                dst_written += w;
            }
        }
    }

    close(src_fd);
    for (int i = 0; i < num_files; i++) {
        close(dest_fd_list[i]);
    }

    free(readStr);
    free(dest_fd_list);

    return 0;
}