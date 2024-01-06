#include "store_information_and_amaliat.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Reset "\033[0m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
int login(struct ATM *store){
    printf(Yellow"             login\n");
    printf("----------------------------------"Reset);
    char ID[100];
    char password[100];
    printf("\nEnter your ID");//get ID from user
    printf(Red"(Enter 0 for exit): "Reset);
    scanf("%s",ID);
    if (ID[0]=='0'){//check the user wants exit from program or not
        exit(0);
    }
    printf("Enter your password: ");//get password from user
    printf(Red"(Enter 0 for exit): "Reset);
    scanf("%s",password);
    if (password[0]=='0'){//check the user wants exit from program or not
        exit(0);
    }

    int i=0;
    //check the account was found or not
    for ( i=0;i<29;i++){
        if (strcmp(store->Account_information[i].id,ID)==0 && strcmp(store->Account_information[i].password,password)==0){
            return i;
        }
    }
    if (i==29){
        printf(Red"Your password or ID is uncorrect!\n\n");
        return -1;
    }
    
}