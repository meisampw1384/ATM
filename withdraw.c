#include "store_information_and_amaliat.h"
#include <stdio.h>
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"

// function to handle withdrawing money from an account
void withdraw(struct ATM *store, int index) {
    int inedx_hesab = index;
    int withdraw_money;
    int balance_before = store->Account_information[inedx_hesab].balance_account;
    
    // prompting the user for the amount to withdraw
    printf(Yellow"How much do you want to withdraw from your account?"Red);
    printf("(Enter 0 for go to menu)"Reset);
    printf("\nEnter:");
    scanf("%d", &withdraw_money);
    
    // checking if user wants to go back to the main menu
    if (withdraw_money == 0) {
        menu(store, index);
    }
    
    // validating if the account has sufficient balance for the withdrawal
    if (withdraw_money <= store->Account_information[inedx_hesab].balance_account) {
        // performing the withdrawal and displaying success message
        store->Account_information[inedx_hesab].balance_account -= withdraw_money;
        printf(Green"\t\tThe operation was successful\n"Reset);
        printf(Green"-------------------------------------------\n"Reset);
        printf("Account number: %d\n", store->Account_information[inedx_hesab].Account_number);
        printf("Name of bank: %s\n", store->Account_information[inedx_hesab].bank_name);
        printf("Balance before withdraw: %d\n", balance_before);
        printf("Amount of withdraw: %d\n", withdraw_money);
        printf("Balance after withdraw: %d\n\n", store->Account_information[inedx_hesab].balance_account);
        
        // prompting the user to return to the main menu
        ATM_exit(store);
        int exit;
        printf(Red"Enter 0 for go to menu:"Reset);
        scanf("%d", &exit);
        printf("\n");
        if (exit == 0) {
            menu(store, index);
        }
    } else {
        // notifying the user about insufficient balance and prompting to return to the main menu
        int exit;
        printf(Red"You dont have enough balance in the account!\n\n");
        printf(Red"Enter 0 for go to menu:"Reset);
        scanf("%d", &exit);
        printf("\n");
        if (exit == 0) {
            menu(store, index);
        }
    }
}