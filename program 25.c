#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    lseek(fd, 0, SEEK_SET);
    struct stat st;
    stat("test.txt", &st);
    DIR *d = opendir(".");
    struct dirent *dir = readdir(d);
    closedir(d);
    close(fd);
    return 0;
}