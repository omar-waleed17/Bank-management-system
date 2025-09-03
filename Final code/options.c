#include "options.h"
// _____________
void add()
{
    account new_account;
    int option1,option2;
    FILE*f;
    time_t t=time(NULL);
    struct tm tm = *localtime(&t);

    while(1)
    {
        printf("Enter new account number: ");
        scanf("%s",new_account.acc_no);
        getchar();

        if(strlen(new_account.acc_no)!=10)
        {
            printf("Invalid account number input(length)\n");
            continue;
        }
    
        //check for duplicate//
        if(is_duplicate(new_account.acc_no))
        { 
            printf("Account number %s already exists.\n",new_account.acc_no);
            continue;
        }
        //check if all are digits//
        if(is_all_digits(11,new_account.acc_no)!=10)
        {
            printf("Invalid account number input(non-digit)\n");
            continue;
        }
        break;
    }

    new_account.name=malloc(75);
    new_account.email=malloc(75);

    printf("Enter new account name: ");
    fgets(new_account.name,75,stdin);
    // new_account.name=realloc(new_account.name,strlen(new_account.name)+1);
    new_account.name[strlen(new_account.name)-1]='\0';

    printf("Enter new account email: ");
    fgets(new_account.email,75,stdin);
    // new_account.email=realloc(new_account.email,strlen(new_account.email)+1);
    new_account.email[strlen(new_account.email)-1]='\0';

    printf("Enter new account balance: ");
    scanf("%f",&new_account.balance);

    char *new_mobile=malloc(12);
    while(1)
    {
        char *temp=malloc(12);
        printf("Enter new account mobile: "); 
        scanf("%s",temp);
        getchar();
        
        if(strlen(temp)!=11)
        {
            printf("Invalid mobile input(length)\n");
            continue;
        }
        
        if (is_all_digits(12,temp)!=11)
        {
            printf("Invalid mobile input(non-digit)\n");
            continue;
        }
        strcpy(new_account.mobile,temp);
        free(temp);
        break;
    }    
    
    new_account.date_opened.month=tm.tm_mon+1;
    new_account.date_opened.year=tm.tm_year+1900;

    while(1)
    {   
        printf("Would you like to save?\n1. Yes\n2. No\n");
        scanf("%d",&option2);
        if(option2==1)
            {
            char new_file_name[20];
            sprintf(new_file_name,"accounts\\%s.txt",new_account.acc_no);
            f=fopen(new_file_name,"w");
            count_acc++;
            accounts=realloc(accounts,count_acc * sizeof(account));
            accounts[count_acc-1]=new_account;
            fclose(f);
            free(new_account.name);
            free(new_account.email);
            printf("Saved\n");
            printf("Add: \n");
            print_accounts();
            SAVE();
            return;
            }
        else if(option2==2){
            printf("Not saved\n");
            return;
            }
        else
            printf("Invalid choice");
    }
}

void DELETE(int count_acc)
{
    char del_acc_no[11];
    int i=0,option;
    printf("Enter the account number of the account you want to delete: ");
    fgets(del_acc_no,11,stdin);
    getchar();
    while(i<count_acc)
    {
        if(strcmp(del_acc_no,accounts[i].acc_no)==0)
        {
            if(accounts[i].balance>0)
            {
                printf("Account balance is greater than zero (%f$)\ndeletion rejected",accounts[i].balance);
                return;
                getchar();
            }
            printf("Are you sure you want to delete account %s ?\n1. Yes\n2. No\n",accounts[i].acc_no);
            scanf("%d",&option);
            if(option==1)
            {
                accounts[i]=accounts[count_acc-1];
                count_acc--;
                accounts=realloc(accounts,count_acc * sizeof(account));
                printf("Account deleted succefully");
                getchar();
                SAVE();
            }
            else
            {
                return;
            }
        }
        else
        {
            i++;
            return;
        }
       
    }
    printf("Account number does not exist");
    return;
}

void modify(int count_acc)
{
    char mod_acc_no[11];
    int i=0,option,option1;

    while(1)
        {
        printf("Enter the account number of the account you want to modify: ");
        scanf("%s",mod_acc_no);     //check that they are digits//
        if(strlen(mod_acc_no)!=10)
        {
            printf("Invalid account number input(length)\n");
            continue;
        }
        if(is_all_digits(11,mod_acc_no)!=10)
        {
            printf("Invalid account number input(non-digit)\n");
            continue;
        }
        break;
        }
    getchar();

while(i<count_acc)
    {
        if(strcmp(mod_acc_no,accounts[i].acc_no)==0)
        {
            do
            {
                printf("What do you want to modify?\n1. Name\n2. Email\n3. Mobile\n4. (Done)\n");
                scanf("%d",&option);
                getchar();
                switch (option)
                {
                case 1:
                    printf("Previous name: %s\n",accounts[i].name);
                    printf("Enter new name: ");
                    char *new_name=malloc(75);
                    fgets(new_name,75,stdin);
                    new_name[strlen(new_name)-1]='\0';
                    while(1)
                    {
                        printf("Do you want to save?\n1. Yes\n2. No\n");
                        scanf("%d",&option1);
                        if(option1==1)
                        {
                            accounts[i].name=realloc(accounts[i].name,strlen(new_name)+1);
                            strcpy(accounts[i].name,new_name);
                            free(new_name);
                            break;
                        }
                        else if(option1==2)
                        {
                            free(new_name);
                            break;
                        }
                        else
                            printf("Invalid input\n");
                    }
                    break;
                case 2:
                    printf("Previous email: %s\n",accounts[i].email);
                    printf("Enter new email: ");
                    char *new_email=malloc(75);
                    fgets(new_email,75,stdin);
                    new_email[strlen(new_email)-1]='\0';

                    while(1)
                    {
                        printf("Do you want to save?\n1. Yes\n2. No\n");
                        scanf("%d",&option1);
                        if(option1==1)
                        {   
                            accounts[i].email=realloc(accounts[i].email,strlen(new_email)+1);
                            strcpy(accounts[i].email,new_email);
                            free(new_email); 
                            printf("Save successful\n");
                            break;
                        }
                        else if(option1==2)
                        {
                            free(new_email);
                            break;
                        }
                        else
                            printf("invalid input\n");          
                    }

                    break; 
                case 3:
                    printf("Previous mobile: %s\n",accounts[i].mobile);     //mobile validation
                    
                    char *new_mobile=malloc(12);
                    while(1)
                    {
                        char *temp=malloc(12);
                        printf("Enter new mobile: "); 
                        scanf("%s",temp);
                        getchar();
                        
                        if(strlen(temp)!=11)    //check that its a correct length
                        {
                            printf("Invalid mobile input(length)\n");
                            continue;
                        }
                        
                        if (is_all_digits(12,temp)!=11) //check that all are digit
                        {
                            printf("Invalid mobile input(non-digit)\n");
                            continue;
                        }
                        strcpy(new_mobile,temp);
                        free(temp);
                        break;
                    }
                    
                    while(1)
                    {
                        printf("Do you want to save?\n1. Yes\n2. No\n");
                        scanf("%d",&option1);
                        if(option1==1)
                        {
                            strcpy(accounts[i].mobile,new_mobile);
                            free(new_mobile);
                            printf("Save successful\n");
                            break;
                        }
                        else if(option1==2)
                        {
                            free(new_mobile);
                            break;
                        }
                        else
                            printf("Invalid input\n");
                    }
                    break;
                case 4:
                    SAVE();
                    printf("Saved");
                    return;
                    break;         
                default:
                    printf("Invalid input\n");
                    break;
                }

            }while(1);

        }
        else
        {
            i++;
        }
       
    }
    printf("Account number does not exist");
    return;
}

// _____________
void SEARCH()
{
    int i=0,flagfound=0,monthInNumber;
    char *monthname; //will use it to convert month from integer like 3 to March
    char searching_account[50] ;


    do
    {
        printf("Enter your 10-digit account number: ");
        scanf("%s",searching_account);

        // Check if the length is exactly 10
        if (strlen(searching_account) != 10)
        {
            printf("Invalid input. Please enter a 10-digit account number.\n");
            continue;  // Ask for input again
        }

        // Validate if all characters are digits
        int j = 0;
        while (searching_account[j] != '\0')
        {
            if (!isdigit(searching_account[j]))
            {
                printf("Invalid input. Please enter a 10-digit account number.\n");
                break;  // Ask for input again
            }
            j++;
        }

        if (j == 10)
        {
            // If the program reaches here, the input is a valid 10-digit number

            break;  // Exit the loop
        }

    }
    while (1);    // Infinite loop until a valid input is provided



    for(i=0; i<1; i++)
    {
         if (strcmp(searching_account, accounts[i].acc_no) == 0) //seeing if the entered account matches an account in our system if yes print the details of this account
        {
            printf(" Account number : %s \n",accounts[i].acc_no);
            printf(" Name : %s \n",accounts[i].name);
            printf(" email: %s\n",accounts[i].email);
            printf(" Balance: %0.2f$\n",accounts[i].balance);
            printf(" Mobile:%s \n",accounts[i].mobile);
            monthInNumber=accounts[i].date_opened.month;
            monthname=(char *)month_name(monthInNumber);
            printf(" Date Opened  %s %d", monthname,accounts[i].date_opened.year);
            flagfound=1;
            break;

        }
    }
    if(flagfound==0) //flagfound not updated indicating no account found with the accoutn number user entered
    {
        printf(" the account with the following account number is not found :%s ",searching_account);
    }
}

void advanced_search()
{
    char key_string[100];
    char*found_Keystring;
    char *monthname;
    int monthInNumber,counting_accounts=0,i;
    printf("please enter the  keyword\n");  //keyword your are searching for between names in our bank management system
                    scanf("%s",key_string);                       // scanf(" %[^\n]", key_string);
    for (i=0; i<count_acc; i++)
    {
        found_Keystring=strstr(accounts[i].name,key_string);   //returns pointer fist occurence of the key name in this account. can be found or not found then it will contain null
        if( found_Keystring != NULL && *found_Keystring != '\0')                               //indicates that the record of this customer has that keyword in his name
        {
            printf(" Account number : %s \n",accounts[i].acc_no);
            printf(" Name: %s \n",accounts[i].name);
            printf(" email: %s\n",accounts[i].email);
            printf(" Balance: %0.2f $\n",accounts[i].balance);
            printf(" Mobile:%s \n",accounts[i].mobile);
            monthInNumber=accounts[i].date_opened.month;
            monthname=(char *)month_name(monthInNumber);     //function convert month number like 3 to name like March
            printf(" Date Opened  %s %d \n\n", monthname,accounts[i].date_opened.year);
            counting_accounts++;     //incrementing the accounts to see how many accounts has this key word in their names
        }
    }
    if(counting_accounts==0)      //no customer has this keyword in his name
    {
        printf("no matching records are found for this keyword");
    }
}

// _____________
void withdraw()
{
    char account_number[100], withdrew_money_check[100], Continue[100], confirmation[100];
    int check_digits, validation, count = 0, check_exist = 0, number_of_digits;
    char *ptr;
    float withdrew_money;

    do
    {
        printf("Enter 10-digit account number: ");
        scanf("%s", account_number);

        validation = validation_acc_no(account_number);
    }
    while(validation);

    for(count = 0; count < count_acc; count++)
    {
        if(strcmp(account_number, accounts[count].acc_no) == 0)
        {
            check_exist = 1;
            break;
        }
    }

    if(!check_exist)
    {
        printf("Account number doesn't exist.\n");

        printf("\nDo you want to restart or exit?\n");

        do
        {
            printf("To restart press number 1.\n");
            printf("To exit press number 0.\n");
            scanf("%s", Continue);

            number_of_digits = strlen(Continue);
        }
        while(number_of_digits != 1 || !isdigit(Continue[0]) || (Continue[0] != '1' && Continue[0] != '0'));

        if(Continue[0] == '0')
            return;

        withdraw();
        return;
    }

    printf("\nMaximum withdrawal limit is 10,000$ per transaction.\n");

    do
    {
        validation = 0;
        check_digits = 0;

        printf("Enter amount to be withdrew: ");
        scanf("%s", withdrew_money_check);

        number_of_digits = strlen(withdrew_money_check);

        for(int i = 0; i < number_of_digits; i++)
        {
            if(!isdigit(withdrew_money_check[i]) && withdrew_money_check[i] != '.')
            {
                check_digits = 1;
                validation = 1;
                break;
            }
        }

        if(check_digits)
            printf("Please enter digits only.\n");
        else
        {
            withdrew_money = strtof(withdrew_money_check, &ptr);

            if(withdrew_money > 10000)
            {
                validation = 1;
                printf("Enter amount to be withdrew: ");
                scanf("%f", &withdrew_money);
            }
        }
    }
    while(validation);

    withdrew_money = strtof(withdrew_money_check, &ptr);

    if(withdrew_money > accounts[count].balance)
    {
        printf("Insufficient money!\n");
        return;
    }

    printf("\nDo you want to save this transaction?\n");

    do
    {
        printf("To confirm press number 1.\n");
        printf("To cancel press number 0.\n");
        scanf("%s", confirmation);

        number_of_digits = strlen(confirmation);
    }
    while(number_of_digits != 1 || !isdigit(confirmation[0]) || (confirmation[0] != '1' && confirmation[0] != '0'));

    if(confirmation[0] == '1')
    {
        accounts[count].balance -= withdrew_money;
        SAVE();
        printf("Transaction was successful.\n");
    }
}

void transfer()
{
    char account_number_sender[100], account_number_receiver[100], transfered_money_check[100];
    char Continue_sender[100], Continue_receiver[100], confirmation[100];
    int check_digits_sender, validation_sender, count_sender = 0, check_exist_sender = 0, number_of_digits;
    int check_digits_receiver, validation_receiver, count_receiver = 0, check_exist_receiver = 0;
    char *ptr;
    float transfered_money;

    printf("For sender\n");
    do
    {
        printf("Enter 10-digit account number: ");
        scanf("%s", account_number_sender);

        validation_sender = validation_acc_no(account_number_sender);
    }
    while(validation_sender);

    printf("\nFor receiver\n");
    do
    {
        printf("Enter 10-digit account number: ");
        scanf("%s", account_number_receiver);

        validation_receiver = validation_acc_no(account_number_receiver);
    }
    while(validation_receiver);

    for(count_sender = 0; count_sender < count_acc; count_sender++)
    {
        if(strcmp(account_number_sender, accounts[count_sender].acc_no) == 0)
        {
            check_exist_sender = 1;
            break;
        }
    }

    if(!check_exist_sender)
    {
        printf("Account number of sender doesn't exist.\n");

        printf("\nDo you want to restart or exit?\n");

        do
        {
            printf("To restart press number 1.\n");
            printf("To exit press number 0.\n");
            scanf("%s", Continue_sender);

            number_of_digits = strlen(Continue_sender);
        }
        while(number_of_digits != 1 || !isdigit(Continue_sender[0]) || (Continue_sender[0] != '1' && Continue_sender[0] != '0'));

        if(Continue_sender[0] == '0')
            return;

        transfer();
        return;
    }

    for(count_receiver = 0; count_receiver < count_acc; count_receiver++)
    {
        if(strcmp(account_number_receiver, accounts[count_receiver].acc_no) == 0)
        {
            check_exist_receiver = 1;
            break;
        }
    }

    if(!check_exist_receiver)
    {
        printf("Account number of receiver doesn't exist.\n");

        printf("\nDo you want to restart or exit?\n");

        do
        {
            printf("To restart press number 1.\n");
            printf("To exit press number 0.\n");
            scanf("%s", Continue_receiver);

            number_of_digits = strlen(Continue_receiver);
        }
        while(number_of_digits != 1 || !isdigit(Continue_receiver[0]) || (Continue_receiver[0] != '1' && Continue_receiver[0] != '0'));

        if(Continue_receiver[0] == '0')
            return;

        transfer();
        return;
    }

    do
    {
        validation_sender = 0;
        check_digits_sender = 0;

        printf("\nEnter amount to be transfered: ");
        scanf("%s", transfered_money_check);

        number_of_digits = strlen(transfered_money_check);

        for(int i = 0; i < number_of_digits; i++)
        {
            if(!isdigit(transfered_money_check[i]) && transfered_money_check[i] != '.')
            {
                check_digits_sender = 1;
                validation_sender = 1;
                break;
            }
        }

        if(check_digits_sender)
            printf("Please enter digits only.\n");
    }
    while(validation_sender);

    transfered_money = strtof(transfered_money_check, &ptr);

    if(transfered_money > accounts[count_sender].balance)
    {
        printf("Insufficient money!\n");
        return;
    }

    printf("\nDo you want to save this transaction?\n");

    do
    {
        printf("To confirm press number 1.\n");
        printf("To cancel press number 0.\n");
        scanf("%s", confirmation);

        number_of_digits = strlen(confirmation);
    }
    while(number_of_digits != 1 || !isdigit(confirmation[0]) || (confirmation[0] != '1' && confirmation[0] != '0'));

    if(confirmation[0] == '1')
    {
        accounts[count_sender].balance -= transfered_money;
        accounts[count_receiver].balance += transfered_money;
        SAVE();
        printf("Transaction was successful.\n");
    }
}

void deposit()
{
    char account_number[100], deposited_money_check[100], confirmation[100], Continue[100];
    int check_digits, validation, count = 0, check_exist = 0, number_of_digits;
    char *ptr;
    float deposited_money;

    do
    {
        printf("Enter 10-digit account number: ");
        scanf("%s", account_number);

        validation = validation_acc_no(account_number);
    }
    while(validation);

    for(count = 0; count < count_acc; count++)
    {
        if(strcmp(account_number, accounts[count].acc_no) == 0)
        {
            check_exist = 1;
            break;
        }
    }

    if(!check_exist)
    {
        printf("Account number doesn't exist.\n");

        printf("\nDo you want to restart or exit?\n");

        do
        {
            printf("To restart press number 1.\n");
            printf("To exit press number 0.\n");
            scanf("%s", Continue);

            number_of_digits = strlen(Continue);
        }
        while(number_of_digits != 1 || !isdigit(Continue[0]) || (Continue[0] != '1' && Continue[0] != '0'));

        if(Continue[0] == '0')
            return;

        deposit();
        return;
    }

    printf("\nMaximum deposit limit is 10,000$ per transaction.\n");

    do
    {
        validation = 0;
        check_digits = 0;

        printf("Enter amount to be deposited: ");
        scanf("%s", deposited_money_check);

        number_of_digits = strlen(deposited_money_check);

        for(int i = 0; i < number_of_digits; i++)
        {
            if(!isdigit(deposited_money_check[i]) && deposited_money_check[i] != '.')
            {
                check_digits = 1;
                validation = 1;
                break;
            }
        }

        if(check_digits)
            printf("Please enter digits only.\n");
        else
        {
            deposited_money = strtof(deposited_money_check, &ptr);

            if(deposited_money > 10000)
            {
                validation = 1;
                printf("Enter amount to be deposited: ");
                scanf("%f", &deposited_money);
            }
        }
    }
    while(validation);

    deposited_money = strtof(deposited_money_check, &ptr);

    printf("\nDo you want to save this transaction?\n");

    do
    {
        printf("To confirm press number 1.\n");
        printf("To cancel press number 0.\n");
        scanf("%s", confirmation);

        number_of_digits = strlen(confirmation);
    }
    while(number_of_digits != 1 || !isdigit(confirmation[0]) || (confirmation[0] != '1' && confirmation[0] != '0'));

    if(confirmation[0] == '1')
    {
        accounts[count].balance += deposited_money;
        SAVE();
        printf("Transaction was successful.\n");
    }
}

// _____________
FILE *open_tran_file(char *acc_no, char type[3]){
    // Open transaction file and handle open error
    char path[26] = "accounts/";
    strcat(path, acc_no);
    strcat(path, ".txt");

    FILE *file = fopen(path, type);
    return file;
}

char* load_transaction(FILE *transactions_file, int no_of_entries, int elimenate){
    // Load transaction array
    char *transactions = malloc(5 * 40 * sizeof(char));
    int loop_end = no_of_entries;
    if ((no_of_entries >= 5) && elimenate){
        // to elimenate oldest entry if more than 5
        fgets(transactions, 39, transactions_file);             
        loop_end--;
    }
    for(int i=0; i<loop_end; i++){
        fgets(transactions+(i*40), 39, transactions_file);
    }
    return transactions;
}

char* new_transaction(int type, float amount, char *transfered_acc){
    // returns entry string
    const char *type_to_str[] = {"withdraw: ", "deposit: ", "transfer: ", "transfer: "};
    char * new_entry = malloc(40 * sizeof(char));
    char amount_str[10];
    
    snprintf(amount_str, sizeof(amount_str), "%.2f", amount);
    strcpy(new_entry, type_to_str[type]);
    strcat(new_entry, amount_str);
    
    if(type >=2){
        const char *temp = (type == 3) ? " from " : " to ";
        strcat(new_entry, temp);
        strcat(new_entry, transfered_acc); 
    }

    strcat(new_entry,"\n");
       
    return new_entry;
}

void add_transaction_to_file(char *acc_no, int type, float amount, char *transfered_acc){
    FILE *transactions_file = open_tran_file(acc_no, "r+");
    if (transactions_file == NULL){
            printf("Error opening file\n");
            exit(0);
        }
    char *transactions;
    int no_of_entries = no_accounts(transactions_file);

    // load transactions into an array 
    transactions = load_transaction(transactions_file, no_of_entries, 1);

    // add new transaction
    if (no_of_entries == 5) no_of_entries =4;
    char *new_entry = new_transaction(type, amount, transfered_acc);
        strcpy(transactions+ (no_of_entries*40), new_entry);
    free(new_entry);
    fclose(transactions_file);

    // write new file
    transactions_file = open_tran_file(acc_no, "w+");
    for(int i=0; i<no_of_entries+1; i++){
        fprintf(transactions_file, "%s", transactions + i*40);
    }

    fclose(transactions_file);
    free(transactions);
}

void report(){
    char *acc_no;
    FILE *transactions_file;
    int i = 0;
    do{
        if(i>0){ 
            printf("Invalid account number pleaser try again\n");
            free(acc_no);
        }
        acc_no = enter_valid_acc();
        transactions_file = open_tran_file(acc_no, "r+");
        i++;
    }while(transactions_file == NULL);
    int no_of_entries = no_accounts(transactions_file);

    // load transactions into an array
    char *transactions = load_transaction(transactions_file, no_of_entries, 0);

    // print transactions
    printf("Latest Transactions:\n");
    for(i=0; i<no_of_entries; i++){
        printf("%d) %s", i+1, transactions+(i*40));
    }

    free(acc_no);
    free(transactions);
    fclose(transactions_file);
}

void swap_acc(account *a, account *b){
    account temp = *a;
    *a = *b;
    *b = temp;
}

int datecmp(date a, date b){
    // return 1 if a>b, 0 if ==, -1 if b>a
    if (a.year == b.year){
        if(a.month > b.month) return 1;
        else if(a.month == b.month) return 0;
        else return -1;
    }else return a.year>b.year? 1:-1;
}

int compare_vals(int j, int type){
    // return the comparison depending on type of sort
    if (type == 0){ 
        // Sort by name
        return (strcmp(accounts[j].name, accounts[j+1].name)>0);
    }else if(type == 1){
        // sort by date
        return (datecmp(accounts[j].date_opened, accounts[j+1].date_opened) > 0);
    }else{
        // sort by balance
        return (accounts[j].balance < accounts[j+1].balance)? 1: 0;
    }
}

void sort(int type){
    // bubble sort
    int swapped = 0;
    for(int i=1; i<count_acc; i++){
        swapped = 0;
        for(int j=0; j<count_acc-i; j++){
            if(compare_vals(j, type)){
                swap_acc(&(accounts[j]), &(accounts[j+1]));
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void print_accounts(){
    const char *num_to_name[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int i;
    char *monthname; //will use it to convert month from integer
    for(i=0; i<count_acc; i++){
        printf("_________%d_________\n", i+1);
        printf(" Account number : %s \n",accounts[i].acc_no);
        printf(" Name : %s \n",accounts[i].name);
        printf(" email: %s\n",accounts[i].email);
        printf(" Balance: %0.2f$\n",accounts[i].balance);
        printf(" Mobile:%s \n",accounts[i].mobile);
        printf(" Date Opened: %s %d\n", num_to_name[accounts[i].date_opened.month],accounts[i].date_opened.year);
    }
}

// _____________
void SAVE ()
{
    int i;
    FILE *f;
    f=fopen("accounts.txt","w");
    if(f!=NULL)     
    {
        printf("Count: %d\n", count_acc);
        printf("Save: \n");
        print_accounts();
        for ( i = 0; i < count_acc; i++)
        {
            fprintf(f, "%s,%s,%s,%.2f,%s,%d-%d\n",
                    accounts[i].acc_no,
                    accounts[i].name,
                    accounts[i].email,
                    accounts[i].balance,
                    accounts[i].mobile,
                    accounts[i].date_opened.month,
                    accounts[i].date_opened.year);
        }
        printf("Saved 5las\n");
    }


    fclose(f);
}


