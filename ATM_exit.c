#include "store_information_and_amaliat.h"
#include <stdio.h>

void ATM_exit (struct ATM *store){
    FILE *data;
    data=fopen("data.txt","w");
    for (int i=0;i<29;i++){
        fprintf(data, "%s %s %s %s %d %d %s\n",  store->Account_information[i].first_name,  store->Account_information[i].last_name, store->Account_information[i].id, store->Account_information[i].bank_name, store->Account_information[i].Account_number, store->Account_information[i].balance_account, store->Account_information[i].password);
    }
    fclose(data);
}