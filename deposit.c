#include <stdio.h>
#include "store_information_and_amaliat.h"
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"

// function to handle depositing money into an account
void deposit(struct ATM *store, int index) {
    int inedx_hesab = index;
    int deposit_money;
    int balance_before = store->Account_information[inedx_hesab].balance_account;
    
    // prompting the user for the amount to deposit
    printf(Yellow"How much do you want to deposit in your account?"Red);
    printf("(Enter 0 for go to menu)"Reset);
    printf("\nEnter:");
    scanf("%d", &deposit_money);
    
    // checking if user wants to go back to the main menu
    if (deposit_money == 0) {
        menu(store, index);
    }
    else {
        // adding the deposited amount to the account balance
        store->Account_information[inedx_hesab].balance_account += deposit_money;
        
        // displaying success message and account details after deposit
        printf(Green"\t\tThe operation was successful\n"Reset);
        printf(Green"-------------------------------------------\n"Reset);
        printf("Account number: %d\n", store->Account_information[inedx_hesab].Account_number);
        printf("Name of bank: %s\n", store->Account_information[inedx_hesab].bank_name);
        printf("Balance before deposit: %d\n", balance_before);
        printf("Amount of deposit: %d\n", deposit_money);
        printf("Balance after deposit: %d\n", store->Account_information[inedx_hesab].balance_account);
        
        // prompting the user to return to the main menu
        ATM_exit(store);
        int exit;
        printf(Red"Enter 0 for go to menu:"Reset);
        scanf("%d", &exit);
        printf("\n");
        if (exit == 0) {
            menu(store, index);
        }
    }
}