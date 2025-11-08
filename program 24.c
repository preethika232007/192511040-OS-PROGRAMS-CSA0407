#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buffer[100];
    fd = open("test.txt", O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    write(1, buffer, sizeof(buffer));
    close(fd);
    return 0;
}