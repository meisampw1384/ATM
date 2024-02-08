#include <stdio.h>
#include <stdlib.h>
#include "store_information_and_operations.h"
void ATM_initializer(struct ATM *account)
{
    account->Account_information = (struct Account *)malloc(29 * sizeof(struct Account));
    FILE *data;
    data = fopen("data.txt", "r");
    int i = 0;
    while (fscanf(data, "%s %s %s %s %d %d %s\n", account->Account_information[i].first_name, account->Account_information[i].last_name, account->Account_information[i].id, account->Account_information[i].bank_name, &account->Account_information[i].Account_number, &account->Account_information[i].balance_account, account->Account_information[i].password) != EOF)
    {
        i++;
    }
    fclose(data);
}