#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    while(1) {
        printf("%lu\n", (unsigned long)getpid());
        sleep(1);
    }

    return 0;
}