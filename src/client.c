#include "client.h"

void setName_f(Client *client, char newName[nameLength])
{
    for (int i = 0; i < nameLength; i++)
        client->name[i] = newName[i];
}
void setLastName_f(Client *client, char newLastName[nameLength])
{
    for (int i = 0; i < nameLength; i++)
        client->lastname[i] = newLastName[i];
}
void setAge_f(Client *client, int newAge)
{
    client->age = newAge;
}
void setId_f(Client *client, int newId)
{
    client->id = newId;
}
char *clientToStr_f(Client *client)
{
    char *output = malloc(sizeof(Client));
    sprintf(output, "%s %s age: %d", client->name, client->lastname, client->age);
    return output;
}

// new client with default values
Client *newClient()
{
    Client *client = malloc(sizeof(Client));
    // connecting functions to struct
    client->setName = setName_f;
    client->setLastName = setLastName_f;
    client->setAge = setAge_f;
    client->setId = setId_f;
    client->toString = clientToStr_f;
    return client;
}

// new client with custom values
Client *newClientCustom(char name[nameLength], char lastname[nameLength], int age, int id)
{
    Client *client = malloc(sizeof(Client));
    client->setName = setName_f;
    client->setLastName = setLastName_f;
    client->setAge = setAge_f;
    client->setId = setId_f;
    client->toString = clientToStr_f;
    client->setName(client, name);
    client->setLastName(client, lastname);
    client->setAge(client, age);
    client->setId(client, id);

    return client;
}