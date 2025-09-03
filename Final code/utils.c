#include "utils.h"

char* enter_valid_acc(){
    int validation = 0;
    int check_digits = 0;
    char *acc_no = malloc(11* sizeof(char));
    do{
        validation = 0;
        check_digits = 0;
        printf("Enter 10-digit account number: ");
        scanf("%s", acc_no);
        int number_of_digits = strlen(acc_no);

        for(int i = 0; i < number_of_digits; i++)
        {
            if(!isdigit(acc_no[i]))
            {
                check_digits = 1;
                validation = 1;
                break;
            }
        }

        if(check_digits)
            printf("Please enter digits only.\n");
        else if(number_of_digits != 10)
        {
            printf("Account number must be a 10-digit number.\n");
            validation = 1;
        }
    }
    while(validation);

    return acc_no;
}

int no_accounts(FILE *f)
{
    int count=0;
    char c;
    while((c= fgetc(f))!=EOF)
    {
        if(c=='\n') count++;
    }
    fseek(f, 0, SEEK_SET);
    return count;
}

const char *month_name(int n)
{
    switch(n)
    {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
    }
    return "error";
}


int is_all_digits(int n,char new_acc_no[n])
{
    int i=0;
    while(new_acc_no[i]!='\0')
    {
        if(!isdigit(new_acc_no[i]))
            return 0;
        i++;
    }
    return i;
}

int is_duplicate(char new_acc_no[11])
{
    FILE *f=fopen("accounts.txt","r");
    char *buffer=malloc(100);
    char saved_acc_no[11];
    while(!feof(f))
    {
        fgets(buffer,100,f);
        sscanf(buffer,"%[^,]",saved_acc_no);
        if(strcmp(new_acc_no,saved_acc_no)==0)
        {
            free(buffer);
            return 1;
        }
    }
    fclose(f);
    free(buffer);       
    return 0;
}

int validation_acc_no(char *account_number)
{
    int validation = 0, number_of_digits, check_digits = 0;

    number_of_digits = strlen(account_number);

    for(int i = 0; i < number_of_digits; i++)
    {
        if(!isdigit(account_number[i]))
        {
            check_digits = 1;
            validation = 1;
            break;
        }
    }

    if(check_digits)
        printf("Please enter digits only.\n");
    else if(number_of_digits != 10)
    {
        printf("Account number must be a 10-digit number.\n");
        validation = 1;
    }

    return validation;
}

void quit(int i){
    exit(0);
}