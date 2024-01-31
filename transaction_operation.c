#include "store_information_and_operations.h"
#include <stdio.h>
#include <string.h> 
#include <conio.h>

#define ClearScreen "\033[H\033[J"
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"

struct transaction temp;
//this function reset struct for ready to get another infomations
void reset_struct() {
    for (int i = 0; i < 10; i++) {
        temp.Amount_exchanged[i] = 0;
        temp.balance[i]=0;
        strcpy(temp.status_of_exchanged[i], "");
    }
}
//فhis function shows whether the file exists or not
int file_existed(char name_file[]) {
    FILE *file;
    file = fopen(name_file, "r");
    if (file) {
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}
//this function write information about transaction in file 
void writefile_transaction(char name_file[]) {
    int len = 0;
    FILE *file;
    file = fopen(name_file, "w");
    while (temp.Amount_exchanged[len] != 0 && len<10) {
        fprintf(file, "%d %s balance: %d\n", temp.Amount_exchanged[len], temp.status_of_exchanged[len],temp.balance[len]);
        len++;
    }
    fclose(file);
}
//this function open a new file
void openfile(char name_file[]) {
    FILE *file;
    file = fopen(name_file, "w");
    fclose(file);
}
//this function read information about transaction from file
void readfile_transaction(char name_file[]) {
    if (file_existed(name_file)) {
        FILE *file;
        file = fopen(name_file, "r");
        if (!feof(file)) {
            int i = 0;
            while (fscanf(file, "%d %s balance:%d\n", &temp.Amount_exchanged[i], temp.status_of_exchanged[i],&temp.balance[i]) != EOF) {
                i++;
            }
        }
        fclose(file);
    } else {
        openfile(name_file);
    }
}
//this function updates the information about withdrawing money from the account
void withdraw_transaction(int amount_withdrawn, char name_file[],struct ATM *account,int index_account) {
    readfile_transaction(name_file);
    int len = 0;
    //Gets the length of the array
    while (temp.Amount_exchanged[len] != 0&& len<10) {
        len++;
    }
    //If the length of the array is less than ten, it adds the information to the end of the array
    if (len < 10) {
        temp.Amount_exchanged[len] = amount_withdrawn;
        temp.balance[len]=account->Account_information[index_account].balance_account;
        strcpy(temp.status_of_exchanged[len], "withdrawal");
        len++;
    //If the length of the array is less than ten, it moves the array information back by one and then adds the information to the end of the array
    } else {
        for (int i = 0; i < 10; i++) {
            temp.Amount_exchanged[i] = temp.Amount_exchanged[i + 1];
            temp.balance[i]=temp.balance[i+1];
            strcpy(temp.status_of_exchanged[i], temp.status_of_exchanged[i + 1]);
        }
        temp.Amount_exchanged[9] = amount_withdrawn;
        temp.balance[9]=account->Account_information[index_account].balance_account;
        strcpy(temp.status_of_exchanged[9], "withdrawal");
    }
    writefile_transaction(name_file);
    reset_struct();
}
//this function updates the information about depositing money from the account
void deposit_transaction(int amount_deposit, char name_file[],struct ATM *account,int index_account) {
    readfile_transaction(name_file);
    int len = 0;
    while (temp.Amount_exchanged[len] != 0&& len<10) {
        len++;
    }
    if (len < 10) {
        temp.Amount_exchanged[len] = amount_deposit;
        temp.balance[len]=account->Account_information[index_account].balance_account;
        strcpy(temp.status_of_exchanged[len], "deposited");
        len++;
    } else {
        for (int i = 0; i < 10; i++) {
            temp.Amount_exchanged[i] = temp.Amount_exchanged[i + 1];
            temp.balance[i]=temp.balance[i+1];
            strcpy(temp.status_of_exchanged[i], temp.status_of_exchanged[i + 1]);
        }
        temp.Amount_exchanged[9] = amount_deposit;
        temp.balance[9]=account->Account_information[index_account].balance_account;
        strcpy(temp.status_of_exchanged[9], "deposited");
    }
    writefile_transaction(name_file);
    reset_struct();
}
void show_transaction(char name_file[],struct ATM* account,int index_account) {
    printf(ClearScreen);
   readfile_transaction(name_file);
    int len=0;
    while(temp.Amount_exchanged[len]!=0&&len<10){
        if (strcmp(temp.status_of_exchanged[len],"deposited")==0){
        printf(Green "amount of deposited: %d  amount of balance: %d\n", temp.Amount_exchanged[len],temp.balance[len]);
        len++;
        }
        else{
            printf(Red "amount of withdrawal: %d  amount of balance: %d\n",temp.Amount_exchanged[len],temp.balance[len]);
            len++;
        }
    }
    printf(Reset"\n");
    printf(Red "Press on <esc> for Exit" Reset);
    int input;
    input=getch();
    if (input==27){
          reset_struct();
          menu(account,index_account);
    }

   
   
}
