#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./03_execve <program path> [OPTION]...\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        execve(argv[1], &argv[1], environ);
        _exit(1);
    }

    int status;
    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
        printf("Child exited with code: %d\n", WEXITSTATUS(status));
    }

    return 0;
}