#ifndef CLIENT_H_
#define CLIENT_H_
#include <stdio.h>
#include <stdlib.h>

#define nameLength 32

typedef struct Client
{
    char name[nameLength];
    char lastname[nameLength];
    int age;
    int id;
    void (*setName)(struct Client *, char[nameLength]);
    void (*setLastName)(struct Client *, char[nameLength]);
    void (*setAge)(struct Client *, int);
    void (*setId)(struct Client *, int);
    char *(*toString)(struct Client *);

} Client;
void setName_f(Client *client, char newName[nameLength]);
void setLastName_f(Client *client, char newLastName[nameLength]);
void setAge_f(Client *client, int newAge);
void setId_f(Client *client, int newId);
char *clientToStr_f(Client *client);
Client *newClient();
Client *newClientCustom(char name[nameLength], char lastname[nameLength], int age, int id);
#endif