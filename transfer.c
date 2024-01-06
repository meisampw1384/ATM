#include "store_information_and_amaliat.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
// function to transfer money from one account to another
void transfer_money(struct ATM *store,int index){
    int destination_account_number;
    char destination_name_bank[100];
    //get destination account and information of destination account
    printf("\nEnter the destination account number");
    printf(Red"(Enter 0 for go to menu): "Reset);
    scanf("%d",&destination_account_number);
    //check if the user want to go to the menu
    if (destination_account_number==0){
        menu(store,index);
    }
    //get destination account and information of destination account
    printf("Enter the destination name of the bank");
    printf(Red"(Enter 0 for go to menu): "Reset);
    scanf("%s",destination_name_bank);
    //check if the user want to go to the menu
    if (destination_name_bank[0]=='0'){
        menu(store,index);
    }
    int i;
    for ( i=0;i<29;i++){
        //Checks the given information whether it is correct or not
        if (store->Account_information[i].Account_number==destination_account_number && strcmp(destination_name_bank,store->Account_information[i].bank_name)==0){
            // Prompting the user for the amount of money to be transferred
           printf("\nHow much money do you want to transfer?");
           printf(Red"(Enter 0 for go to menu)"Reset);
           printf("\nEnter:");
           int amount_of_transfer_money;
           scanf("%d",&amount_of_transfer_money);
           printf("\n");
            //checks whether the account balance is sufficient to transfer this money or not
           if (amount_of_transfer_money>store->Account_information[index].balance_account){
            // Notifying the user about insufficient balance
                printf(Red"\nYou dont have enough balance in the account!");
                printf(Red" (Enter 0 for go to menu):"Reset);
                int exit;
                scanf("%d",&exit);
                printf("\n");
                //return to the main menu
                if (exit==0)
                menu(store,index);
           }
        
           else {
                store->Account_information[index].balance_account-=amount_of_transfer_money;
                store->Account_information[i].balance_account+=amount_of_transfer_money;
                printf(Green"\t\tThe operation was successful\n"Reset);
                printf(Green"--------------------------------------------------------------------------------------\n"Reset);
                printf("Your account number: %d\n",store->Account_information[index].Account_number);
                printf("Your bank name: %s\n",store->Account_information[index].bank_name);
                printf("Destination account number: %d\n",store->Account_information[i].Account_number);
                printf("Destination bank name: %s\n",store->Account_information[i].bank_name);
                printf("The amount of money transferred: %d\n",amount_of_transfer_money);
                printf(Red"\nEnter 0 for go to menu:\n");
                ATM_exit(store);
                int exit;
                scanf("%d",&exit);
                printf("\n");
                //return to the main menu
                if (exit==0)  
                menu(store,index);
           }
    }
    }
// Notifying the user if the destination account or bank name is not found
if (i==29){
    printf(Red"The account number or name of the destination bank is not correct\n"Reset);
    printf(Red"Enter 0 for go to menu:"Reset);
    int n;
    scanf("%d",&n);
    if (n==0){
        menu(store,index);
    }
}
}