#include <stdio.h>
#include "store_information_and_operations.h"
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"

// function to handle depositing money into an account
void deposit(struct ATM *account, int index) {
    int inedx_hesab = index;
    int deposit_money;
    int balance_before = account->Account_information[inedx_hesab].balance_account;
    
    // prompting the user for the amount to deposit
    printf(Yellow"How much do you want to deposit in your account?"Red);
    printf("(Enter 0 for go to menu)"Reset);
    printf("\nEnter:");
    scanf("%d", &deposit_money);
    
    // checking if user wants to go back to the main menu
    if (deposit_money == 0) {
        menu(account, index);
    }
    if(deposit_money<0){
        printf(Red"\n The choice is not valid\n"Reset);
        menu(account,index);
    }
    else {
        // adding the deposited amount to the account balance
        account->Account_information[inedx_hesab].balance_account += deposit_money;
        
        // displaying success message and account details after deposit
        printf(Green"\t\tThe operation was successful\n"Reset);
        printf(Green"-------------------------------------------\n"Reset);
        printf("Account number: %d\n", account->Account_information[inedx_hesab].Account_number);
        printf("Name of bank: %s\n", account->Account_information[inedx_hesab].bank_name);
        printf("Balance before deposit: %d\n", balance_before);
        printf("Amount of deposit: %d\n", deposit_money);
        printf("Balance after deposit: %d\n", account->Account_information[inedx_hesab].balance_account);
        
        // prompting the user to return to the main menu
        ATM_exit(account);
        char name_file[20];
        //convert int to string
        sprintf(name_file,"%d",account->Account_information[index].Account_number);
        deposit_transaction(deposit_money,name_file,account,inedx_hesab);
        int exit;
        printf(Red"Enter 0 for go to menu:"Reset);
        scanf("%d", &exit);
        printf("\n");
        if (exit == 0) {
            menu(account, index);
        }
    }
}