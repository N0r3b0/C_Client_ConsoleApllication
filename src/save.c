#include <stdio.h>
#include "client.h"
#include "clientArray.h"
#include "passwd.c"
#include "author.c"

void saveUserList()
{
    FILE *out = fopen("users.bin", "wb");
    if (out == NULL)
    {
        printf("ERROR: file didn't open correctly");
        return;
    } 

    // UsersList *users2 = malloc(sizeof(UsersList));

    size_t elements_written = fwrite(&users, sizeof(UsersList), 1, out);
    if (elements_written != 1)
    {
        perror("Error writing struct to file");
        return;
    }
    elements_written = fwrite(users.list, sizeof(User), users.size, out);
    if (elements_written != users.size)
    {
        perror("Error writing data array to file");
        return;
    }
    // Close the file
    fclose(out);

    // Free the memory allocated for the struct
    free(users.list);
}
void loadUserList()
{
    // Allocate memory for the struct
    FILE *fp = fopen("users.bin", "rb");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    // Read the struct from the file
    size_t elements_read = fread(&users, sizeof(UsersList), 1, fp);
    if (elements_read != 1)
    {
        perror("Error reading struct from file");
        return;
    }

    // Allocate memory for the data array
    users.list = (User *)malloc(sizeof(User) * users.size);

    // Read the data array from the file
    elements_read = fread(users.list, sizeof(User), users.size, fp);
    if (elements_read != users.size)
    {
        perror("Error reading data array from file");
        return;
    }

    // Close the file
    fclose(fp);
}

/* int main()
{
    //saveUserList();
    loadUserList();
    return 0;
} */