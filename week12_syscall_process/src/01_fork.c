#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;
    child_pid = fork();

    if (child_pid == 0) {
        printf("child pid: %lu\n", (unsigned long)getpid());
        printf("child ppid: %lu\n", (unsigned long)getppid());
        return 7;
    }
    else {
        int wstatus;

        waitpid(child_pid, &wstatus, 0);
        if (WIFEXITED(wstatus)) {
            printf("Child exited with status: 7\n");
        }
        printf("parent pid: %lu\n", (unsigned long)getpid());
        printf("parent ppid: %lu\n", (unsigned long)getppid());
    }
    return 0;
}