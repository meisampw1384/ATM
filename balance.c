#include <stdio.h>
#include <stdlib.h>
#include "store_information_and_amaliat.h"
#include <stdlib.h>
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
void check_balance(struct ATM *store,int index){
    printf("Acount number: %d\n",store->Account_information[index].Account_number);
    printf("Name of bank: %s\n",store->Account_information[index].bank_name);
    printf("Your Balance: %d\n",store->Account_information[index].balance_account);
    printf(Red"Enter 0 for go to menu:"Reset);
        int exit;
        scanf("%d",&exit);
        printf("\n");
        if (exit==0){   
        menu(store,index);
        }
}