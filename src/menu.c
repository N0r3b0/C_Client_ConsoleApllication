#include <stdio.h>
#include "client.h"
#include "clientArray.h"
#include "save.c"

void cleanBuff()
{
    printf("\nInvalid choice\n");
    int c;
    while ((c = getchar()) != '\n' && c != EOF) // clear buffer in case wrong input
        ;
}

void clientChoice(int *choice) // client option WORKINPROGRESS TODO: client add, network operators, connect with account, client rm
{
    while (1)
    {
        printf("\n");
        printf("1. Send ticket to your provider where you can describe your problem\n");
        printf("2. Check your previous tickets\n");
        printf("3. Go back\n");
        if (scanf("%d", choice) != 1)
        {
            cleanBuff();
        }
        else
        {
            if (*choice == 1) // Show all users
            {
                printUsers();
            }
            else if (*choice == 2) // Add user manually
            {
                createUser();
            }
            else if (*choice == 3) // Go back
            {
                return;
            }
            else
            {
                printf("\nInvalid choice\n");
            }
        }
    }
}
/* void clientChoiceAdmin(int *choice) // client option WORKINPROGRESS TODO: client add, network operators, connect with account, client rm
{
    while (1)
    {
        printf("\n");
        printf("1. \n");
        printf("2. Add user manually\n");
        printf("3. Remove user\n");
        printf("4. Go back\n");
        if (scanf("%d", choice) != 1)
        {
            cleanBuff();
        }
        else
        {
            if (*choice == 1) // Show all users
            {
                printUsers();
            }
            else if (*choice == 2) // Add user manually
            {
                createUser();
            }
            else if (*choice == 3) // Remove user
            {
                rmUser();
            }
            else if (*choice == 4) // Go back
            {
                return;
            }
            else
            {
                printf("\nInvalid choice\n");
            }
        }
    }
} */

void adminChoice(int *choice) // admin options
{
    while (1)
    {
        printf("\n");
        printf("1. Show all users\n");
        printf("2. Add user manually\n");
        printf("3. Remove user\n");
        printf("4. Go back\n");
        if (scanf("%d", choice) != 1)
        {
            cleanBuff();
        }
        else
        {
            if (*choice == 1) // Show all users
            {
                printUsers();
            }
            else if (*choice == 2) // Add user manually
            {
                createUser();
            }
            else if (*choice == 3) // Remove user
            {
                rmUser();
            }
            else if (*choice == 4) // Go back
            {
                return;
            }
            else
            {
                printf("\nInvalid choice\n");
            }
        }
    }
}

void helpChoice(int *choice) // help options
{
    while (1)
    {
        printf("\n");
        //printf("1. informataions\n");
        printf("1. Author and Information\n");
        printf("2. Go back\n");
        if (scanf("%d", choice) != 1)
        {
            cleanBuff();
        }
        else
        {
            if (*choice == 1) // decription
            {
                description();
            }
            else if (*choice == 2) // go back
            {
                return;
            }
            else
            {
                printf("\nInvalid choice\n");
            }
        }
    }
}

int main()
{

    int choice;

    loadUserList();
    while (1)
    {
        printf("\n");
        loginInf();
        printf("\nMenu:\n");
        printf("1. Client options\n");
        printf("2. Sign in\n");
        printf("3. Login\n");
        printf("4. Log off\n");
        printf("5. Remove account\n");
        printf("6. Admin options\n");
        printf("7. HELP\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            cleanBuff();
        }
        else
        {
            if (choice == 1) // Client options TO DO: it
            {
                if (isLogged == true && loggedUser.clientConnected == true && strcmp(loggedUser.userName, admin.userName) != 0)
                    //client connected options
                if (isLogged == true && loggedUser.clientConnected == false && strcmp(loggedUser.userName, admin.userName) != 0)
                    createClient();
                if(isLogged == true && strcmp(loggedUser.userName, admin.userName) == 0)
                    //clientChoiceAdmin(&choice); //TO DO
                if(isLogged == false)   printf("\nYou need to be logged in to use this option\n");
            }
            else if (choice == 2) // Sign in
            {
                createUser();
            }
            else if (choice == 3) // Login
            {
                login();
                printf("\n");
            }
            else if (choice == 4) // Log off
            {
                logoff();
                printf("\n");
            }
            else if (choice == 5) // Remove account
            {
                rmUser();
                printf("\n");
            }
            else if (choice == 6) // Admin options
            {
                if (strcmp(loggedUser.userName, admin.userName) == 0)
                    adminChoice(&choice);
                else
                    printf("\nthis option is intended for admin access only. You need admin permissions\n");
            }
            else if (choice == 7) // Help, Information about author
            {
                helpChoice(&choice);
            }
            else if (choice == 8) // Exit
            {
                saveUserList();
                printf("\nExiting program\n");
                break;
            }
            else
            {
                printf("\nInvalid choice\n");
            }
        }
    }

    return 0;
}