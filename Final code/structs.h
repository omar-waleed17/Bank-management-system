#ifndef _STRUCT_H_
#define _STRUCT_H_

typedef struct
{
    int month;
    int year;
} date;
typedef struct
{
    char acc_no[11];
    char *name;
    char *email;
    float balance;
    char mobile[12];
    date date_opened;
} account;
typedef struct
{
    char username[20];
    char password[7];
} user;

extern account *accounts;
extern int count_acc;

#endif