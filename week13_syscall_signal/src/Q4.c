#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sigint_handler(int sig) {
    printf("[SIGINT handler] ----------\n");
    pid_t pid = fork();

    if (pid == 0) {
        char *args[] = {"/bin/ls", NULL};
        execve("/bin/ls", args, NULL);

        perror("execve ls");
        exit(1);
    }
    else {
        wait(NULL);
    }
}

void sigquit_handler(int sig) {
    printf("[SIGQUIT handler] ----------\n");
    pid_t pid = fork();

    if (pid == 0) {
        char *args[] = {"/usr/bin/date", NULL};
        execve("/bin/date", args, NULL);

        perror("execve date");
        exit(1);
    }
    else {
        wait(NULL);
    }
}

void sigalrm_handler(int sig) {
    printf("[SIGALRM handler] ----------\n");
    pid_t pid = fork();

    if (pid == 0) {
        char *args[] = {"/usr/bin/whoami", NULL};
        execve("/usr/bin/whoami", args, NULL);

        perror("execve whoami");
        exit(1);
    }
    else {
        wait(NULL);
    }
    alarm(3);
}

int main() {

    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGALRM, sigalrm_handler);


    alarm(3);

    while (1) {
        sleep(1);
    }

    return 0;
}