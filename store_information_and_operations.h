//define structures
struct Account{
    char first_name[100];
    char last_name[100];
    char id[100];
    char password[100];
    int Account_number;
    char bank_name[100];
    int balance_account;
};
struct ATM{
    struct Account* Account_information;
};
struct transaction{
    int Amount_exchanged[10];
    char status_of_exchanged[10][30];
    int balance[10];
};
//this function get data from file and save it in structures
void ATM_initializer(struct ATM *account);

//this function write data and modify data in file data.txt
void ATM_exit(struct ATM *account);

//this function login in to ATM
int  menu_login(struct ATM *account);

//this function give the menu or operations
void menu(struct ATM *account,int index_account);

//this function take money from your account
void withdraw(struct ATM *account,int index_account);

//this function invest money in your account
void deposit(struct ATM *account,int index_account);

//this function check your amount of balance
void check_balance(struct ATM *account,int index_account);

//this function transfer money in another account
void transfer_money(struct ATM *account,int index_account);



//All the following functions are for transaction capture

//this function show transaction for user
void show_transaction(char name[],struct ATM *account,int index_account);
//this function shows the transactions that have been added to the money account.
void deposit_transaction(int amount_deposit,char name[],struct ATM *account,int index_account);
//This function shows the transactions that have been removed from the money account.
void withdraw_transaction(int amount_withdrawn,char name[],struct ATM *account,int index_account);
//This function read data about transactions in file
void readfile_transaction(char name[]);
//This function write data about transaction in file
void writefile_transaction(char name[]);