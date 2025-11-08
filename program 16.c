#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct employee e;
    fp = fopen("employee.dat", "rb+");
    if (fp == NULL) fp = fopen("employee.dat", "wb+");
    scanf("%d%s%f", &e.id, e.name, &e.salary);
    fseek(fp, (e.id - 1) * sizeof(e), SEEK_SET);
    fwrite(&e, sizeof(e), 1, fp);
    fclose(fp);
    return 0;
}