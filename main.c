#include "client.h"

int main()
{
  while(1)
  {
    printf("\n bank database system\n");
    printf(" please enter number between 1 and 6\n\n 1- create client account to the bank\n 2- edit client account's data\n 3- delete client account from the bank\n 4- print client data\n 5- transfer money from bank account to anther \n 6- print all accounts data in the bank\n 7- close the system of bank\n");
    int choise = 0;
    scanf("%d", &choise);

    switch(choise)
    {
    case 1:
      create_client();
      break;
    case 2:
      edit_client_data();
      break;
    case 3:
      delete_client();
      break;
    case 4:
      print_client_data();
      break;
    case 5:
      transfer_money();
      break;
    case 6:
      print_all_accounts();
      break;
    case 7:
      system("pause");
      return 0;
    default:
      printf("please enter number between 1 and 6.\n");
      break;

    }
  }
  /*
  client_t create_client(void);
  void edit_client_data(int client_id);
  void delete_client(int client_id);
  void print_client_data(int client_id);
  void transfer_money(int sender_id, int receiver_id, double amount_of_money);

  client = create_client();
  printf("client : %s %s %0.2lf %d\n", client.name, client.account_type, client.balance, client.id);
  bank[clientCount++] = client;


  for(int i = 0; i< MAX_NUMBER_OF_CLIENTS; ++i){
    client = bank[i];
    printf("client : %s %s %0.2lf %d\n", client.name, client.account_type, client.balance, client.id);
  }

  system("pause");
  return 0;
  */
}
