#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "clientArray.c"

#define passwdSize 30

typedef struct User
{
    char userName[passwdSize];
    char password[passwdSize];
    Client userClientAcc;
    bool logged;
    bool clientConnected;
} User;
typedef struct UsersList
{
    User *list;
    size_t size;
} UsersList;

ClientArrayList list;
int globalID = 0;

User admin = {"Admin", "Admin123", false};

UsersList users = {.size = 0}; // set list size to 0 at start
User loggedUser = {.userName = "Logged off"};
bool isLogged = false;

int findUserInList(User user) // returns passed user index
{
    for (int id = 0; id < users.size; id++)
    {
        if (strcmp(users.list[id].userName, user.userName) == 0 && strcmp(users.list[id].password, user.password) == 0)
            return id;
    }
    return -1; // error code
}
int findUsernameInList(User user) // returns passed user index
{
    for (int id = 0; id < users.size; id++)
    {
        if (strcmp(users.list[id].userName, user.userName) == 0)
            return id;
    }
    return -1; // error code
}
void createUser()
{
    while (1)
    {
        User newUser;
        printf("\ntype back for going back\n");
        printf("Your username: ");
        scanf("%s", newUser.userName);
        if (strcmp(newUser.userName, "back") == 0)
            return;
        if (strcmp(newUser.userName, admin.userName) == 0)
        {
            printf("You can't name yourself Admin\n");
            continue;
        }
        printf("Your password: ");
        scanf("%s", newUser.password);
        if (strcmp(newUser.password, "back") == 0)
            return;
        int check = findUsernameInList(newUser);
        if (check != -1)
        {
            printf("This username is already taken, try again\n");
            continue;
        }
        newUser.logged = false;
        newUser.clientConnected = false;
        users.size++;
        users.list = realloc(users.list, sizeof(User) * users.size);
        users.list[users.size - 1] = newUser;
        return;
    }
}
User createUserCustom(char username[passwdSize], char password[passwdSize]) //? why while
{
    while (1)
    {
        User newUser;
        strcpy(newUser.userName, username);
        strcpy(newUser.password, password);
        int check = findUsernameInList(newUser);
        if (check != -1)
        {
            printf("This username is already taken, try again\n");
            continue;
        }
        newUser.logged = false;
        newUser.clientConnected = false;
        users.size++;
        users.list = realloc(users.list, sizeof(User) * users.size);
        users.list[users.size - 1] = newUser;
        return newUser;
    }
}
void rmUserFromList(int rmIndex)
{
    if (rmIndex > users.size - 1)
    {
        printf("\nwrong index value\n\n");
        return;
    }
    users.size--;
    User *newList = malloc(sizeof(User) * users.size);
    for (int i = 0; i < users.size + 1; i++)
    {
        if (i < rmIndex)
            newList[i] = users.list[i];
        if (i == rmIndex)
            continue;
        if (i > rmIndex)
            newList[i - 1] = users.list[i];
    }
    users.list = realloc(users.list, sizeof(User) * users.size);
    for (int i = 0; i < users.size; i++)
        users.list[i] = newList[i];
    free(newList);
}
void rmUser()
{
    printf("REMOVING USER\n");
    User user;
    printf("Your username: ");
    scanf("%s", user.userName);
    printf("Your password: ");
    scanf("%s", user.password);
    int index = findUserInList(user);
    if (index == -1)
    {
        printf("\nWrong username or password\n\n");
        return;
    }
    printf("User %s has been removed\n", user.userName);
    rmUserFromList(index);
}

/* void login(User user) //function not needed at the moment
{

    int id = 0;
    user.logged = false;
    for (id = 0; id < users.size; id++)
    {
        if (strcmp(users.list[id].userName, user.userName) == 0 && strcmp(users.list[id].password, user.password) == 0)
            user.logged = true;
    }
    if (user.logged == true)
        printf("Logged in\n");
    if (user.logged == false)
        printf("Invalid username or password");
} */
void login()
{
    if (isLogged == true)
    {
        printf("You are already logged in");
        return;
    }
    printf("Login\n");
    User user;
    printf("Your username: ");
    scanf("%s", user.userName);
    printf("Your password: ");
    scanf("%s", user.password);

    if (strcmp(user.userName, admin.userName) == 0 && strcmp(user.password, admin.password) == 0)
    {
        user.logged = true;
        printf("Logged in as admin\n");
        loggedUser = admin;
        isLogged = true;
        return;
    }

    user.logged = false;
    int id = 0;
    for (id = 0; id < users.size; id++)
    {
        if (strcmp(users.list[id].userName, user.userName) == 0 && strcmp(users.list[id].password, user.password) == 0)
            user.logged = true;
    }
    if (user.logged == true)
        printf("Logged in\n");
    if (user.logged == false)
    {
        printf("Invalid username or password");
        return;
    }
    loggedUser = user;
    isLogged = true;
}

void logoff()
{
    if (isLogged == true)
    {
        printf("Logged off");
        isLogged = false;
        strcpy(loggedUser.userName, "Logged off");
    }
    if (isLogged == false)
        "You re not logged in";
}

void loginInf()
{
    printf("Account: %s\n", loggedUser.userName);
}

void connectClientToUser(User user, Client client)
{
    if (user.clientConnected == true)
        printf("\nThis account already has client connceted\n");

    if (user.clientConnected == false)
    {
        printf("\nYour account has been successfully conencted\n");
        user.userClientAcc = client;
        user.clientConnected = true;
    }
}

void createClient()
{
    while (1)
    {
        Client newClient;
        printf("\nPASS THE INFORMATION ABOUT YOU AND YOUR PROVIDER\n");
        printf("\ntype back for going back\n");
        printf("Your name: ");
        scanf("%s", newClient.name);
        if (strcmp(newClient.name, "back") == 0)
            return;

        printf("Your last name: ");
        scanf("%s", newClient.lastname);
        if (strcmp(newClient.lastname, "back") == 0)
            return;

        printf("Your age: ");
        int age;
        scanf("%d", &age);
        newClient.age = age;

        printf("Select your internet provider from list below (numbers only): \n");
        int selected;
        listOfProviders();
        scanf("%d", &selected);
        if (selected < 0 || selected > 4)
        {
            printf("wrong provider");
            continue;
        }
        newClient.netProvider = selected;

        // int check = findInArray(&list, newClient);

        globalID++;
        newClient.id = globalID;
        list.size++;
        list.array = realloc(list.array, sizeof(Client) * list.size);
        list.array[list.size - 1] = newClient;
        int index = findUserInList(loggedUser);
        connectClientToUser(users.list[index], newClient);
        return;
    }
}
void printUsers()
{
    if (users.size == 0)
        printf("\nList of users is empty\n");
    for (int id = 0; id < users.size; id++)
    {
        printf("Username: %s, Password: %s\n", users.list[id].userName, users.list[id].password);
        //printf("%s", clientToString(users.list[id].userClientAcc));
    }
}
/* int main(void) // false 0, true 1
{
    User u1 = createUserCustom("User1", "Password1");
    Client *c1 = newClientCustom("Adam", "Mickiewicz", 53, 2, orange);
    createClient();
    return 0;
} */