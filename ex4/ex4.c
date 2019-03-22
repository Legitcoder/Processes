// Write a program that calls `fork()` and then calls some form of `exec()`
// to run the program `/bin/ls`. Try a few variants of `exec()`, such as 
// `execl()`, `execle()`, `execv()`, and others. Why do you think there 
// are so many variants of the same basic call?

//It appears as though there are many to provide many ways to achieve the same task.
//For example execl requires you to individually pass each command as parameters
//while execv requires you pass the commands in an array and provide the index of the
//starting point.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid = fork();

    if(pid == 0) {
        printf("Child\n");
        execl("/bin/sleep", "sleep", "5", NULL);
        //char *args[]={"/bin/echo", "Hello World,", "My name is Moin Uddin", NULL};
        //execv(args[0], args);
    } else {
        wait(NULL);
        printf("Parent\n");
    }

    return 0;
}
