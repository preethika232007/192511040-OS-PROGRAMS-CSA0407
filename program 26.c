#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char filename[100], ch;
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) exit(0);
    fputc('A', fp);
    fclose(fp);
    fp = fopen(filename, "r");
    if (fp == NULL) exit(0);
    ch = fgetc(fp);
    fclose(fp);
    return 0;
}