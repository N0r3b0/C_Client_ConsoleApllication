#include "client.c"
#include "clientArray.h"

bool clientCmp(Client client1, Client client2)
{
    if (strcmp(client1.name, client2.name) == 0 && strcmp(client1.lastname, client2.lastname) == 0 && client1.age == client2.age && client1.id == client2.id)
        return true;
    else
        return false;
}

int findInArray(ClientArrayList *list, Client client) // returns passed user index
{
    for (int id = 0; id < list->size; id++)
    {
        if (clientCmp(list->array[id], client) == true)
            return id;
    }
    printf("Client not found");
    return -1; // not found
}

void addToArray(ClientArrayList *list, Client added) // add 1 element into the array
{
    list->size++;
    list->array = realloc(list->array, sizeof(Client) * list->size);
    list->array[list->size - 1] = added;
}

void rmFromArray(ClientArrayList *list, int rmIndex) // remove element under passed index from the array
{
    if (rmIndex > list->size - 1)
    {
        printf("wrong index value");
        return;
    }
    list->size--;
    Client *newArray = malloc(sizeof(Client) * list->size);
    for (int i = 0; i < list->size + 1; i++)
    {
        if (i < rmIndex)
            newArray[i] = list->array[i];
        if (i == rmIndex)
            continue;
        if (i > rmIndex)
            newArray[i - 1] = list->array[i];
    }
    list->array = realloc(list->array, sizeof(Client) * list->size);
    for (int i = 0; i < list->size; i++)
        list->array[i] = newArray[i];
    free(newArray);
}
/* 
int main(void)
{
    ClientArrayList *list = malloc(sizeof(ClientArrayList));
    list->size = 0;
    Client *c1 = newClientCustom("Wiktor", "Fedde", 22, 1, 0);
    Client *c2 = newClientCustom("Adam", "Mickiewicz", 53, 2, orange);
    Client *c3 = newClientCustom("Karol", "Wojtyła", 70, 3, 0);
    //printf("%s", c3->name);
    addToArray(list, *c1);
    addToArray(list, *c2);
    addToArray(list, *c3);
    int x = findInArray(list, *c3);
    //printf("%s", enumPrint(3));

    return 0;
    // printf("\n%d\n", list->size);

    // rmFromArray(list, 4);

    printf("\n%ld\n", list->size);
    for (int i = 0; i < list->size; i++)
    {
        printf("%s, ", list->array[i].name);
    } 
} */