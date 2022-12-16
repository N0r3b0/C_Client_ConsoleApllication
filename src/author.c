#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>

#define BUFFER_SIZE 1024

char *readtxt(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return NULL;
    }
    char *buffer = (char *)malloc(BUFFER_SIZE);
    if (buffer == NULL)
    {
        printf("Error allocating memory");
        return NULL;
    }

    size_t bytes_read = fread(buffer, 1, BUFFER_SIZE, file);
    if (ferror(file))
    {
        printf("Error reading file");
        free(buffer);
        return NULL;
    }

    buffer[bytes_read] = '\0';

    fclose(file);
    return buffer;
}

void description()
{
    char *descrpt = readtxt("D:\\Programowanie\\Programowanie_git\\1_MojeProjekty\\OskarProjekt\\final\\description.txt");
    printf("\n%s\n", descrpt);
}