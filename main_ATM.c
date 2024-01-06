#include "store_information_and_amaliat.h"
#include <stdio.h>
#include <stdlib.h>
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
void menu(struct ATM *store,int index){
    printf(Green"\n         Welcome to ATM %s\n",store->Account_information[index].first_name);
    printf("----------------------------------------------------\n"Reset);
    printf("Enter");
    printf(Yellow" 1");
    printf(Reset" to withdraw from the account\n");
     printf("Enter");
    printf(Yellow" 2");
    printf(Reset" for deposit\n");
     printf("Enter");
    printf(Yellow" 3");
    printf(Reset" To check the balance\n");
     printf("Enter");
    printf(Yellow" 4");
    printf(Reset" To transfer money\n");
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
        withdraw(store,index);
        break;
    case 2:
        deposit(store,index);
        break;
    case 3:
        check_balance(store,index);
        break;
    case 4:
        transfer_money(store,index);
        break;
    default:
        printf(Red"Please enter the appropriate option!\n"Reset);
        menu(store,index);
}

}
int main(){
    //We create a structure that is defined in the header file
    struct ATM store;
    //We take the information from the data file and store it in the structure
    ATM_initializer(&store);
    // in this section we login in the ATM
    int index_hesab=login(&store);
    while(index_hesab<0){
        index_hesab=login(&store);
    }
    //When the login is finished, we are opening the menu
    menu(&store,index_hesab);
    return 0;
}