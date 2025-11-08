#include <stdio.h>
#include <string.h>

struct directory {
    char name[10];
    char files[10][10];
    int file_count;
};

int main() {
    struct directory dir[10];
    int dir_count;
    scanf("%d", &dir_count);
    for (int i = 0; i < dir_count; i++) {
        scanf("%s", dir[i].name);
        scanf("%d", &dir[i].file_count);
        for (int j = 0; j < dir[i].file_count; j++) {
            scanf("%s", dir[i].files[j]);
        }
    }
    return 0;
}