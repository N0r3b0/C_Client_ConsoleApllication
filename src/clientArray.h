#ifndef CLIENTARRAY_H_
#define CLIENTARRAY_H_
#include "client.h"

typedef struct ClientArrayList
{
    Client *array;
    size_t size;
} ClientArrayList;

void addToArray(ClientArrayList *list, Client added); // add 1 element into the array
void rmFromArray(ClientArrayList *list, int rmIndex); // remove element under passed index from the array

#endif
