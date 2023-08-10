#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* fp = fopen("test.txt", "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");

    fclose(fp);
}
