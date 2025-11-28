#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = getpid();
    printf("PID: %d", pid);
    return 0;
}