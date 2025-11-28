#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    printf("PID: %d\nPPID: %d", pid, ppid);
    return 0;
}