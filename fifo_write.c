#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

int main(){
    int fd;
    char msg[50];
    char* path = "/tmp/myfifo";

    mkfifo(path, 0666);

    msg[50] = "Sai Charan";

    printf("Writer : waiting for file to read");
    fflush(stdout);

    fd = open(path, O_WRONLY);
    write(fd, msg, 50);
    close(fd);
    printf("SuXess");
    return 0;

}