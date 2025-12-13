#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

struct two_double {
    double a;
    double b;
} data;

void sigalrm_handler(int sig) {
    printf("%f %f\n", data.a, data.b);
    alarm(1);
}

int main(){
    struct sigaction sa_alarm;
    struct two_double zeros = {0.0, 0.0}, ones = {1.0, 1.0};
    sigset_t sigset;

    sa_alarm.sa_handler = sigalrm_handler;
    sigemptyset(&sa_alarm.sa_mask);
    sa_alarm.sa_flags = 0;

    sigaction(SIGALRM, &sa_alarm, NULL);
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGALRM);

    alarm(1);

    for ( ; ; ) {

        //숙제 block unblock 사용해서 정상동작하도록 sigpromask() ??
        //block SIGALRM signal
        sigprocmask(SIG_BLOCK, &sigset, NULL);
        data = ones;
        //unblock SIGALRM signal
        sigprocmask(SIG_UNBLOCK, &sigset, NULL);

        //block SIGALRM signal
        sigprocmask(SIG_BLOCK, &sigset, NULL);
        data = zeros;
        //unblock SIGALRM signal
        sigprocmask(SIG_UNBLOCK, &sigset, NULL);

        // sleep(1);
    }
    return 0;
}