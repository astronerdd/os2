#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int choice, fd;
    char buffer[100];
    struct stat st;
    DIR *d;
    struct dirent *dir;

    while (1) {
        printf("\n1.Open & Write\n2.Read\n3.Seek\n4.Stat\n5.Directory List\n6.Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
            write(fd, "Hello Linux\n", 12);
            printf("Written to file\n");
            close(fd);
            break;

        case 2:
            fd = open("test.txt", O_RDONLY);
            read(fd, buffer, sizeof(buffer));
            printf("Data: %s\n", buffer);
            close(fd);
            break;

        case 3:
            fd = open("test.txt", O_RDONLY);
            lseek(fd, 6, SEEK_SET);
            read(fd, buffer, 5);
            buffer[5] = '\0';
            printf("After seek: %s\n", buffer);
            close(fd);
            break;

        case 4:
            stat("test.txt", &st);
            printf("Size: %ld bytes\n", st.st_size);
            break;

        case 5:
            d = opendir(".");
            while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
            break;

        case 6:
            exit(0);
        }
    }
}