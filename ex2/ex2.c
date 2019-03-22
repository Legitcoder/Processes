// Write a program that opens the text.txt file (with the `fopen()` library call) located in this directory 
// and then calls `fork()` to create a new process. Can both the child and parent access the file descriptor 
// returned by `fopen()`? What happens when they are written to the file concurrently?


// Both Child and Parent can access the file descriptor returned by fopen() and both can
//also write to the same file. It seems as though the parent writes before the child in
// every instance.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    FILE *file = fopen("text.txt", "r+");

    pid_t pid = fork();

    if(pid == 0) {
        printf("Child!\n");

        if(file == NULL) {
            printf("File is not opening!\n");
        }

        fputs("Hello World Child\n", file);
    } else {
        printf("Parent!\n");
        if(file == NULL) {
            printf("File is not opening!\n");
        }

        fputs("Hello World Parent\n", file);
    }

    fclose(file);



    return 0;
}
