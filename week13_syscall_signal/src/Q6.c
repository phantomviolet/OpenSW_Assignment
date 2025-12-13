#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    sigset_t blocksig, pendingsig;

    sigemptyset(&blocksig);
    sigaddset(&blocksig, SIGINT);
    sigprocmask(SIG_BLOCK, &blocksig, NULL);

    printf("SIGINT is blocked. Sleep 5 seconds...\n");
    printf("Try pressing Ctrl+C now.\n");

    sleep(5);

    sigpending(&pendingsig);

    if (sigismember(&pendingsig, SIGINT)) {
        printf("SIGINT is pending\n");
    }
    else {
        printf("SIGINT is not pending\n");
    }

    return 0;
}