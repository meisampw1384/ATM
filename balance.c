#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "store_information_and_operations.h"
#include <stdlib.h>

#define ClearScreen "\033[H\033[J"
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
void check_balance(struct ATM *account,int index_account){
    printf(ClearScreen);
    printf("Acount number: %d\n",account->Account_information[index_account].Account_number);
    printf("Name of bank: %s\n",account->Account_information[index_account].bank_name);
    printf("Your Balance: %d\n",account->Account_information[index_account].balance_account);
    printf(Red"Press on <esc> for Exit"Reset);
        int input;
        input=getch();
        if (input==27){   
        menu(account,index_account);
        }
}
