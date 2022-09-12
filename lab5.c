#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main() {
    pid_t cpid;
    pid_t gcpid;

    // fork another process
    cpid = fork();
    printf("CPID : %d\n", cpid);
    if ( cpid == 0) {
        gcpid = fork();
        printf("GCPID : %d\n", gcpid);
        if ( gcpid == 0) {
            printf("Can you see this3?\n");
            exit(0);
        }
        execlp("/bin/12ls", "ls", NULL);
        // exit(EXIT_FAILURE);
        printf("Can you see this2?\n");
        exit(0);
        
    }
        printf("Can you see this1?\n");
        wait (NULL); printf("Received Child Complete\n");
        exit(0);

    return 0;
}