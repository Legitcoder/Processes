// Write a program that calls `fork()`. Before calling `fork()`, have the main process access a variable
// (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
// What happens to the variable when both the child and parent change the value of x?

//x in both processes is initially 100. The value of x changes within each processes locally after
//assignment so x within the child process in my example changes to 12 while in the parent
//process changes to 123. Afterwards if we print x within main, you're able to see that when
//both processes print x, they print their own local values of x instead of
//the intial fork of the value 100 x was assigned to prior to the fork.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int x = 100;

    pid_t pid = fork();

    if(pid == 0) {
        printf("Child!\n");
        printf("Initial Value of X in Child: %d\n", x);
        x = 12;
        printf("After Assignment in Child x: %d\n", x);
    } else {
        printf("Parent!, pid valyue is %d\n", pid);
        printf("Initial Value of X in Parent: %d\n", x);
        x = 123;
        printf("After Assignment in Parent x: %d\n", x);
    }

    printf("x: %d\n", x);

    printf("\n");

    return 0;
}
