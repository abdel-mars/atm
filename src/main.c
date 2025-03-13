#include "header.h"

void mainMenu(struct User u) {
  int option;
  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\t-->> Feel free to choose one of the options below, %s <<--\n",
         u.name);
  printf("\n\t\t[1]- Create a new account\n");
  printf("\n\t\t[2]- Update account information\n");
  printf("\n\t\t[3]- Check accounts\n");
  printf("\n\t\t[4]- Check list of owned account\n");
  printf("\n\t\t[5]- Make transaction\n");
  printf("\n\t\t[6]- Remove existing account\n");
  printf("\n\t\t[7]- Transfer ownership\n");
  printf("\n\t\t[8]- Exit\n\n\n");
  scanf("\n\t\t%d", &option);

  switch (option) {
  case 1:
    createNewAccount(u);
    break;
  case 2:
    updateAccountInformation(u);
    break;
  case 3:
    checkAccountDetails(u);
    break;
  case 4:
    checkAllAccounts(u);
    break;
  case 5:
    makeTransaction(u);
    break;
  case 6:
    removeAccount(u);
    break;
  case 7:
    transferOwnership(u);
    break;
  case 8:
    exit(1);
    break;
  default:
    printf("Invalid operation!\n");
    exit(1);
  }
};

void initMenu(struct User *u) {
  int r = 0;
  int option;
  system("clear");
  printf("\n\n\t\t======= ATM =======\n");
  printf("\n\t\t-->> Feel free to login / register :\n");
  printf("\n\t\t[1]- login\n");
  printf("\n\t\t[2]- register\n");
  printf("\n\t\t[3]- exit\n\n\n");
  while (!r) {
    scanf("\n\t\t%d", &option);
    switch (option) {
    case 1:
      loginMenu(u->name, u->password);
      if (strcmp(u->password, getPassword(*u)) == 0) {
      } else {
        printf("\n\t\tWrong password or username\n");
        handleFailedLogin(u);
      }
      r = 1;
      break;
    case 2:
      registerMenu(u->name, u->password);
      r = 1;
      break;
    case 3:
      exit(1);
      break;
    default:
      printf("Insert a valid operation!\n");
      exit(1);
    }
  }
};

int main() {
  struct User u;

  initMenu(&u);
  mainMenu(u);
  return 0;
}
