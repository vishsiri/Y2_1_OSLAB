#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <ctype.h>
int main()
{
    char userChoice = 'z';
    while (userChoice != 'q')
    {
        printf("\n");
        printf("a: ls\n");
        printf("b: ps\n");
        printf("c: who\n");
        printf("q: for quit\n");
        printf("\n--> ");
        scanf(" %c", &userChoice);
        printf("\n");
        pid_t pid;
        pid = fork();
        if (pid == 0)
        {
            if (userChoice == 'a')
                execl("/bin/ls", "ls", NULL);
            if (userChoice == 'b')
                execl("/bin/ps", "ps", NULL);
            if (userChoice == 'c')
                execl("/bin/who", "who", NULL);
        }
        wait(NULL);
    }

    printf("Parent Terminate\n");
    return 0;
}