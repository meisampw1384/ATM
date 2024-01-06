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
//this function get data from file and save it in structures
void ATM_initializer(struct ATM *store);

//this function write data and modify data in file data.txt
void ATM_exit(struct ATM *store);

//this function login in to ATM
int  login(struct ATM *store);

//this function give the menu or operations
void menu(struct ATM *store,int index);

//this function take money from your account
void withdraw(struct ATM *store,int index);

//this function invest money in your account
void deposit(struct ATM *store,int index);

//this function check your amount of balance
void check_balance(struct ATM *store,int index);

//this function transfer money in another account
void transfer_money(struct ATM *store,int index);