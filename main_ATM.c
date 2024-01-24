#include "store_information_and_operations.h"
#include <stdio.h>
#include <stdlib.h>

#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
void menu(struct ATM *account,int index){
    printf(Green"\n         Welcome to ATM %s\n",account->Account_information[index].first_name);
    printf("----------------------------------------------------\n"Reset);
    printf("Enter");
    printf(Yellow" 1");
    printf(Reset" to withdraw from the account\n");
     printf("Enter");
    printf(Yellow" 2");
    printf(Reset" for deposit\n");
     printf("Enter");
    printf(Yellow" 3");
    printf(Reset" to check the balance\n");
     printf("Enter");
    printf(Yellow" 4");
    printf(Reset" to transfer money\n");
    printf("Enter");
    printf(Yellow" 5");
    printf(Reset" to check financial transactions\n" );
    printf("Enter");
    printf(Red" 0");
    printf(Reset" for exit\n");
    int n;
    printf(Green"Enter the number:"Reset);
    scanf("%d",&n);
    printf("\n");
    switch (n)
    {
    case 0:
        exit(0);
        break;
    case 1:
        withdraw(account,index);
        break;
    case 2:
        deposit(account,index);
        break;
    case 3:
        check_balance(account,index);
        break;
    case 4:
        transfer_money(account,index);
        break;
    case 5:
        char name_file[20];
        sprintf(name_file,"%d",account->Account_information[index].Account_number);
        show_transaction(name_file,account,index);
        break;
    default:
        printf(Red"Please enter the appropriate option!\n"Reset);
        menu(account,index);
}

}
int main(){
    //We create a structure that is defined in the header file
    struct ATM account;
    //We take the information from the data file and account it in the structure
    ATM_initializer(&account);
    // in this section we login in the ATM
    int index_hesab=login(&account);
    while(index_hesab<0){
        index_hesab=login(&account);
    }
    //When the login is finished, we are opening the menu
    menu(&account,index_hesab);
    return 0;
}