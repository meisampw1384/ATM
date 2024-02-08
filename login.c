#include "store_information_and_operations.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define ClearScreen "\033[H\033[J"
int login(struct ATM *account)
{
    printf(ClearScreen);
    printf(Yellow "             login\n");
    printf("----------------------------------\n" Reset);
    char ID[100];
    char password[100];
    printf("\nEnter your ID:"); // get ID from user
    scanf("%s", ID);
    int len_ID = strlen(ID);

    printf("\nEnter your password: "); // get password from user
    scanf("%s", password);
    int len_password = strlen(password);
    int i = 0;
    // check the account was found or not
    for (i = 0; i < 29; i++)
    {
        if (strcmp(account->Account_information[i].id, ID) == 0 && strcmp(account->Account_information[i].password, password) == 0)
        {
            return i;
        }
    }
    if (i == 29)
    {
        printf(Red "Your password or ID is uncorrect!\n\n");
        Sleep(1000);
        return -1;
    }
}

int menu_login(struct ATM *account)
{
    int selected_button = 0;
    int input;
    do
    {
        printf(ClearScreen);
        printf(Yellow "       ATM\n");
        printf("---------------------\n" Reset);
        for (int i = 0; i < 2; i++)
        {
            if (selected_button == i)
            {
                printf(Blue "-> " Reset);
            }
            switch (i)
            {
            case 0:
                printf("*Go to the login form\n");
                break;

            case 1:
                printf(Red "*Exit" Reset);
                break;
            }
        }
        input = getch();
        switch (input)
        {
        case 72: // up arrow
            selected_button -= 1;
            if (selected_button < 0)
            {
                selected_button = 1;
            }
            break;
        case 80: // down arrow
            selected_button += 1;
            if (selected_button > 1)
            {
                selected_button = 0;
            }
            break;
        case 13: // Enter key
            if (selected_button == 0)
            {
                int index = login(account);
                return index;
            }
            else
            {
                exit(0);
            }
        }
    } while (input != 13);
}
