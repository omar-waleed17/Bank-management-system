#ifndef _OPTIONS_H_
#define _OPTIONS_H_

#include "utils.h"

void add();
void DELETE();
void modify();

void SEARCH();
void advanced_search();

void withdraw();
void deposit();
void transfer();
void add_transaction_to_file(char *acc_no, int type, float amount, char *transfered_to); // add transaction to the account history file (called after withdraw/deposit/transfer)

void report();      // prints latest 5 transactions for the input account number
void print_accounts();   // prints all accounts and their data in the array

void SAVE ();


#endif