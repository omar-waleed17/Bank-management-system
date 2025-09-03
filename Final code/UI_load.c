#include "UI_load.h"
#include "options.h"

void login()
{
    user entered,saved;
    char *buffer= malloc(27);
    FILE *f1= fopen("users.txt","r");
    if(f1==NULL)
    {
        printf("file not found!\n");
        printf("please make sure the file is there, then reopen the program.\n");
        exit(0);
    }
    for(int i=4; i>=0; i--)
    {
        printf("please enter your username: ");
        scanf("%s",entered.username);
        printf("please enter your password: ");
        scanf("%s",entered.password);

        // TEMP
        strcpy(entered.username, "ahmed.mohamed");
        strcpy(entered.password, "123$@1");

        while(!feof(f1))
        {
            fgets(buffer,26,f1);
            sscanf(buffer,"%s %s",saved.username,saved.password);
            if(strcmp(entered.username,saved.username)==0 && strcmp(entered.password,saved.password)==0)
            {
                if(accounts==NULL) load();
                return;
            }
        }
        if(i==0)
        {
            printf("Too many wrong attempts! Try again later\n");
            exit(0);
        }
        printf("Wrong input! %d attempts left\n",i);
    }
}

void empty_file_menu()
{
    char option;
    FILE *f=fopen("accounts.txt","w");
    fclose(f);
    printf("File is empty! Only add function is availabe\n");
    printf("1. Add\n2. Quit\n");
    do{
    printf("Please choose one of the previous options: ");
    getchar();
    option= getchar();
    if(option=='1') add();
    else if(option=='2') quit(0);
    }while(option!='1' && option!='2');
}

void load()
{
    FILE *f1= fopen("accounts.txt","r");
    if(f1==NULL)
    {
        char option;
        printf("file not found!\n");
        printf("1. Check the file and add it, then restart the program to load the file.\n");
        printf("2. Create new file\n");
        do
        {
            printf("Please choose one of the previous options: ");
            option= getchar();
            getchar();
            if(option=='1') quit(0);
            else if(option=='2'){
                empty_file_menu();
                return;
            }
        }
        while(option!='1' && option!='2');
    }
    if(fgetc(f1)==EOF)
    {
        empty_file_menu();
        return;
    }
    count_acc= no_accounts(f1);
    printf("Count %d\n", count_acc);
    accounts= (account *)malloc(count_acc * sizeof(account));
    if(accounts==NULL)
    {
        printf("There isn't enough space to load files, please clear some space before restarting the program");
        quit(0);
    }
    fseek(f1,0,SEEK_SET);
    for(int k=0; k<count_acc; k++)
    {
        char buffer[100];
        char name_temp[30],email_temp[30],date_temp[9];
        if (fgets(buffer, 99, f1) == NULL)
        {
            // Handle potential file read error
            printf("Error reading from file.\n");
            quit(0);
        }

        sscanf(buffer,"%10[^,],%29[^,],%29[^,],%f,%11[^,],%8s",accounts[k].acc_no,name_temp,email_temp,&accounts[k].balance,accounts[k].mobile,date_temp);
        char *newline = strchr(date_temp, '\n');
        if (newline != NULL)
            *newline = '\0';
        sscanf(date_temp,"%d-%d",&accounts[k].date_opened.month,&accounts[k].date_opened.year);
        accounts[k].name= (char *)malloc(strlen(name_temp)+1);
        accounts[k].email= (char *)malloc(strlen(email_temp)+1);
        strcpy(accounts[k].name,name_temp);
        strcpy(accounts[k].email,email_temp);
    }
    printf("Load: \n");
    print_accounts();
    fclose(f1);
}

void call_menu()
{
    int x=1;
    while(1)
    {
        if(x==1) startup();
        x= menu();
    }
}

int menu(){
    int option;
    printf("\nMenu:\n");
    printf("1. Add\n");
    printf("2. Delete\n");
    printf("3. Modify\n");
    printf("4. Search\n");
    printf("5. Advanced Search\n");
    printf("6. Withdraw\n");
    printf("7. Deposit\n");
    printf("8. Transfer\n");
    printf("9. Report\n");
    printf("10. Print\n");
    printf("11. Quit\n");
    printf("Choose one of the previous options: ");
    scanf("%d",&option);
    
    switch(option){
        case 1:
            printf("Adding\n");
            add();
            return 0;
        case 2:
            printf("Deleting\n");
            DELETE();
            return 0;
        case 3:
            printf("Modifying\n");
            modify();
            return 0;
        case 4:
            printf("Searching\n");
            SEARCH();
            return 0;
        case 5:
            printf("Advanced searching\n");
            advanced_search();
            return 0;
        case 6:
            printf("Withdraw\n");
            withdraw();
            return 0;
        case 7:
            printf("Deposit\n");
            deposit();
            return 0;
        case 8:
            printf("Transfer\n");
            transfer();
            return 0;
        case 9:
            printf("Reporting\n");
            report();
            return 0;
        case 10:
            printf("Printing\n");
            print_accounts();
            return 0;
        case 11:
            printf("Quited");
            exit(0);
        }
    return 1;
}

void startup()
{
    int count=0;
    printf("Startup Menu:\n");
    printf("1. Login\n");
    printf("2. Quit\n");
    while(count++<5){
        printf("Choose one of the previous options: ");
        char option= getchar();
        if(option=='\n') option= getchar();
        getchar();
        if(option=='1')
        {
            login();
            printf("SUCCESSFUL LOGIN\n");
            return;
        }
        else if(option=='2') {
            printf("Quited");
            exit(0);
        }
    }   
    if(count>=5){
        printf("Failed to login");
        exit(0);
    } 
}