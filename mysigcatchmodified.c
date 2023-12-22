#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int count= 0;

void newHandler(int signum) {
    if (signum == SIGINT) {
        count++;
        printf("\nThis is the no%d SIGINT signal. In %d Ctrl+C the program will stop\n", count, 3-count);

        if (count== 2) {
            // restore the default behavior for SIGINT
            signal(SIGINT, SIG_DFL);
        }
    }
}

int main() {
    // use a custom signal handler function
    signal(SIGINT, newHandler);

    printf("Waiting to press Ctrl+C.\n");

    // Infinite loop to wait
    while (1) {
    }

    return 0;
}
