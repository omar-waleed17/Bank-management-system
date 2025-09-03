#include "utils.h"
#include "UI_load.h"
#include "options.h"

account *accounts = NULL;
int count_acc = 0;

int main() {
    printf("WELCOME TO THE BANK MANAGEMENT SYSTEM\n");
    call_menu();

    return 0;
}