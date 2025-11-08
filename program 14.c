#include <stdio.h>
#include <string.h>

struct directory {
    char name[10];
    char files[10][10];
    int file_count;
};

int main() {
    struct directory dir;
    scanf("%s", dir.name);
    scanf("%d", &dir.file_count);
    for (int i = 0; i < dir.file_count; i++) {
        scanf("%s", dir.files[i]);
    }
    return 0;
}