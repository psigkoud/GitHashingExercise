#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void Handler(int signum) {
    printf("\nWe caught SIGINT signal\n");
    exit(0);
}

int main() {
    // use a signal handler for SIGINT
    signal(SIGINT, Handler);

    printf("Waiting to press Ctrl+C.\n");

    // Infinite loop to wait
    while (1) {
    }

    return 0;
}
