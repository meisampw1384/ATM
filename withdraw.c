#include "store_information_and_operations.h"
#include <stdio.h>
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"

// function wwithdrawing money from account
void withdraw(struct ATM *account, int index) {
    int inedx_hesab = index;
    int withdraw_money;
    int balance_before = account->Account_information[inedx_hesab].balance_account;
    
    // ask user how much money he want take from account
    printf(Yellow"How much do you want to withdraw from your account?"Red);
    printf("(Enter 0 for go to menu)"Reset);
    printf("\nEnter:");
    scanf("%d", &withdraw_money);
    
    // checking user want back to menu or not
    if (withdraw_money == 0) {
        menu(account, index);
    }
    if (withdraw_money<0){
        printf(Red"\nThe choice is not valid!\n"Reset);
        menu(account,index);
    }
    
    // validating if the account have sufiiciant balance or not
    if (withdraw_money <= account->Account_information[inedx_hesab].balance_account) {
        // give the information of taking money
        account->Account_information[inedx_hesab].balance_account -= withdraw_money;
        printf(Green"\t\tThe operation was successful\n"Reset);
        printf(Green"-------------------------------------------\n"Reset);
        printf("Account number: %d\n", account->Account_information[inedx_hesab].Account_number);
        printf("Name of bank: %s\n", account->Account_information[inedx_hesab].bank_name);
        printf("Balance before withdraw: %d\n", balance_before);
        printf("Amount of withdraw: %d\n", withdraw_money);
        printf("Balance after withdraw: %d\n\n", account->Account_information[inedx_hesab].balance_account);
        
        // user go back to the menu
        ATM_exit(account);
        char name_file[20];
        // convert int to string
        sprintf(name_file,"%d",account->Account_information[index].Account_number);
        withdraw_transaction(withdraw_money,name_file,account,inedx_hesab);
        int exit;
        printf(Red"Enter 0 for go to menu:"Reset);
        scanf("%d", &exit);
        printf("\n");
        if (exit == 0) {
            menu(account, index);
        }
    } else {
        // the user dont have sufficiant balance and user go to the menu
        int exit;
        printf(Red"You dont have enough balance in the account!\n\n");
        printf(Red"Enter 0 for go to menu:"Reset);
        scanf("%d", &exit);
        printf("\n");
        if (exit == 0) {
            menu(account, index);
        }
    }
}