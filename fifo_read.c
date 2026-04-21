#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    int fd;
    char msg[50];
    char* path = "/tmp/myfifo";

    mkfifo(path, 0666);
    
    printf("Reader : Waiting for file to write");
    fflush(stdout);

    fd = open(path, O_RDONLY);
    read(fd, msg, 50);
    close(fd);

    printf("Read");

    return 0;
}