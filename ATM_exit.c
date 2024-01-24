#include "store_information_and_operations.h"
#include <stdio.h>

void ATM_exit (struct ATM *account){
    FILE *data;
    data=fopen("data.txt","w");
    for (int i=0;i<29;i++){
        fprintf(data, "%s %s %s %s %d %d %s\n",  account->Account_information[i].first_name,  account->Account_information[i].last_name, account->Account_information[i].id, account->Account_information[i].bank_name, account->Account_information[i].Account_number, account->Account_information[i].balance_account, account->Account_information[i].password);
    }
    fclose(data);
}