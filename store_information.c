#include <stdio.h>
#include <stdlib.h>
#include "store_information_and_amaliat.h"
void ATM_initializer(struct ATM *store){
    store->Account_information=(struct Account * )malloc(29*sizeof(struct Account));
    FILE *data;
    data=fopen("data.txt","r");
    int i=0;
   while (fscanf(data, "%s %s %s %s %d %d %s\n", store->Account_information[i].first_name, store->Account_information[i].last_name,store->Account_information[i].id,store->Account_information[i].bank_name,&store->Account_information[i].Account_number,&store->Account_information[i].balance_account,store->Account_information[i].password) != EOF) {
        i++;
    }
    fclose(data);
}