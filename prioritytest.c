#include "types.h"
#include "stat.h"
#include "user.h"

void work(int priority) {
    int i;
    int j;
    
    nice(priority);

    printf(1, "PID %d priority %d started\n", getpid(), priority);

    for(i = 0; i < 1000000; i++) {
        for(j = 0; j < 1000; j++) {

        }
    }
    printf(1, "PID %d priority %d finished\n", getpid(), priority);
    exit();
}

int main(void) {
    int i, pid;

    for(i = 1; i <= 4; i++) {
        pid = fork();

        if(pid == 0) {
            work(i);
        }

        if(pid < 0) {
            printf(1, "fork failed\n");
            exit();
        }
    }

    for(i = 0; i < 4; i++) wait();

  exit();
}