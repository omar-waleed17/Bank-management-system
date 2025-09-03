#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "structs.h"

char* enter_valid_acc();
int validation_acc_no(char *account_number);
int no_accounts(FILE *f);
const char *month_name(int n);
int is_all_digits(int n,char new_acc_no[n]);
int is_duplicate(char new_acc_no[11]);
void quit(int i);

#endif