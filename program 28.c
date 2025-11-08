#include <stdio.h>
#include <string.h>

int main() {
    FILE *fp;
    char word[100], line[1000];
    scanf("%s", word);
    fp = fopen("test.txt", "r");
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, word)) {
            printf("%s", line);
        }
    }
    fclose(fp);
    return 0;
}