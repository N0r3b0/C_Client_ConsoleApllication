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
void setNetProvider_f(Client *client, provider newNetProvider)
{
    client->netProvider = newNetProvider;
}

void listOfProviders()
{
    for(int i = 0; i < 5; i++)
        printf("%d - %s\n", i, providerToString(i));
}

char *providerToString(provider net)
{
    char *output = malloc(sizeof(char)*nameLength);
    switch (net)
    {
        case 0: strcpy(output, "Orange"); break;
        case 1: strcpy(output, "Chopin"); break;
        case 2: strcpy(output, "Play"); break;
        case 3: strcpy(output, "Tmobile"); break;
        case 4: strcpy(output, "Pluse"); break;
        default: printf("Couldn't find operator");
    }
    return output;
}
char *clientToStr_f(Client *client)
{
    char *output = malloc(sizeof(Client));
    sprintf(output, "%s %s age: %d Internet: %s", client->name, client->lastname, client->age, providerToString(client->netProvider));
    return output;
}
char *clientToString(Client client)
{
    char *output = malloc(sizeof(Client));
    sprintf(output, "%s %s age: %d Internet: %s", client.name, client.lastname, client.age, providerToString(client.netProvider));
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
    client->setNetProvider = setNetProvider_f;
    client->toString = clientToStr_f;
    return client;
}

// new client with custom values
Client *newClientCustom(char name[nameLength], char lastname[nameLength], int age, int id, provider netProvider)
{
    Client *client = malloc(sizeof(Client));
    client->setName = setName_f;
    client->setLastName = setLastName_f;
    client->setAge = setAge_f;
    client->setId = setId_f;
    client->setNetProvider = setNetProvider_f;
    client->toString = clientToStr_f;
    client->setName(client, name);
    client->setLastName(client, lastname);
    client->setAge(client, age);
    client->setNetProvider(client, netProvider);
    client->setId(client, id);

    return client;
}