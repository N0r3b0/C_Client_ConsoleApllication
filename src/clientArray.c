#include "clientArray.h"

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

/* int main(void)
{
    ClientArrayList *list = malloc(sizeof(ClientArrayList));
    list->size = 0;
    Client c1 = {"adam", "fedde", 32, 12};
    Client c2 = {"Wiktor", "Filipowicz", 11, 823};
    Client c3 = {"Grzegorz", "Darkowski", 23, 10};

    addToArray(list, c1);
    addToArray(list, c2);
    addToArray(list, c3);

    //printf("\n%d\n", list->size);

    //rmFromArray(list, 4);

    printf("\n%ld\n", list->size);
    for (int i = 0; i < list->size; i++)
    {
        printf("%s, ", list->array[i].name);
    }
} */