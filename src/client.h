#ifndef CLIENT_H_
#define CLIENT_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define nameLength 128

typedef enum {orange, chopin, play, tmobile, plus} provider;
typedef struct Client
{
    char name[nameLength];
    char lastname[nameLength];
    int age;
    int id;
    provider netProvider;
    void (*setName)(struct Client *, char[nameLength]);
    void (*setLastName)(struct Client *, char[nameLength]);
    void (*setAge)(struct Client *, int);
    void (*setId)(struct Client *, int);
    void (*setNetProvider)(struct Client *, provider);
    char *(*toString)(struct Client *);
} Client;


void setName_f(Client *client, char newName[nameLength]);
void setLastName_f(Client *client, char newLastName[nameLength]);
void setAge_f(Client *client, int newAge);
void setId_f(Client *client, int newId);
void setNetProvider_f(Client *client, provider newNetProvider);
void listOfProviders();
char* providerToString(provider);
char *clientToStr_f(Client *client);
char *clientToString(Client client);
Client *newClient();
Client *newClientCustom(char name[nameLength], char lastname[nameLength], int age, int id, provider netProvider);
#endif