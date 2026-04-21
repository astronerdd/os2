#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main(){
    int fd[2];
    char message[50];
    pid_t pid;

    pipe(fd);
    pid = fork();

    if(pid>0){
        close(fd[0]);

        write(fd[1], "Pipe is writing.." , 20);
        close(fd[1]);
    }
    else{
        close(fd[1]);

        read(fd[0], message, 50);
        printf("The message is: %s", message);
        close(fd[0]);
    }

    return 0;
}