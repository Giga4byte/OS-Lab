#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main () {
    int fd1 = open("SimpleRead.txt", O_RDONLY);
    if (fd1 == -1) {
        perror("open");
        return 1;
    }
    printf("Open\n");
    close(fd1);
    
    int fd2 = open("SimpleWrite.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd2 == -1) {
        perror("open");
        return 1;
    }
    char *data = "Hello, world\n";
    write(fd2, data, strlen(data));
    close(fd2);
    
    return 0;
}
