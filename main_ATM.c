#include "store_information_and_operations.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define ClearScreen "\033[H\033[J"

void display_menu_button(int selected_button, struct ATM *account, int index_account)
{
    printf(ClearScreen);
    printf(Green "\n         Welcome to ATM %s\n", account->Account_information[index_account].first_name);
    printf("----------------------------------------------------\n" Reset);
    for (int i = 0; i < 5; i++)
    {
        if (i == selected_button)
        {
            printf(Blue "-> " Reset);
        }
        printf("%d.", i + 1);
        switch (i)
        {
        case 0:
            printf("withdraw\n");
            break;
        case 1:
            printf("deposit\n");
            break;
        case 2:
            printf("check the balance\n");
            break;
        case 3:
            printf("transfer money\n");
            break;
        case 4:
            printf("check the financial transactions\n");
            break;
        }
    }
    printf(Red "\nPress on <esc> for Exit\n" Reset);
}
void menu(struct ATM *account, int index_account)
{
    printf(ClearScreen);
    printf(Green "\n         Welcome to ATM %s\n", account->Account_information[index_account].first_name);
    printf("----------------------------------------------------\n" Reset);

    int input;
    int selected_button = 0;
    do
    {
        display_menu_button(selected_button, account, index_account);
        input = getch();
        switch (input)
        {
        case 72: // up arrow key
            selected_button -= 1;
            if (selected_button < 0)
            {
                selected_button = 4;
            }
            break;
        case 80: // down arrow key
            selected_button += 1;
            if (selected_button > 4)
            {
                selected_button = 0;
            }
            break;
        case 27: // esc key
            exit(0);
            break;
        case 13: // enter key
            if (selected_button == 0)
            { // withdraw_money
                withdraw(account, index_account);
            }
            else if (selected_button == 1)
            { // deposit_money
                deposit(account, index_account);
            }
            else if (selected_button == 2)
            { // check balance
                check_balance(account, index_account);
            }
            else if (selected_button == 3)
            { // transfer money
                transfer_money(account, index_account);
            }
            else if (selected_button == 4)
            { // show transactions
                char name_file[20];
                sprintf(name_file, "%d", account->Account_information[index_account].Account_number);
                show_transaction(name_file, account, index_account);
            }
        }
    } while (input != 13); // when press on enter,the loop is finished
}
int main()
{
    // We create a structure that is defined in the header file
    struct ATM account;
    // We take the information from the data file and account it in the structure
    ATM_initializer(&account);
    // in this section we login in the ATM
    int index_account = menu_login(&account);
    while (index_account < 0)
    {
        index_account = menu_login(&account);
    }
    // When the login is finished, we are opening the menu
    menu(&account, index_account);
    return 0;
}