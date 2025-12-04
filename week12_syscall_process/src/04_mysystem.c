#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char *command) {
    pid_t pid;
    int status;

    if (command == NULL) {
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        return -1;
    }

    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        _exit(1);
    }

    waitpid(pid, &status, 0);
    return status;
}

int main() {

    // system("ls -l | wc -l");
    // system("find . -name '*.c'");
    mysystem("ls -l | wc -l");
    mysystem("find . -name '*.c'");

    printf("Good Bye~\n");
    return 0;
}