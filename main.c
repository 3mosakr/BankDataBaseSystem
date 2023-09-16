#include "client.c"

#define MAX_NUMBER_OF_CLIENTS 3

int clientCount = 0;
client_t bank[MAX_NUMBER_OF_CLIENTS];

int main()
{
  printf("bank database system\n");
  create_client();

  system("pause");
  return 0;
}