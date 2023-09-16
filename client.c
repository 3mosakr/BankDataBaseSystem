#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

void create_client(void)
{
  char name[50] = "\0", account_type[7] = "\0";
  double balance = 0.0f;
  int id = 0;

  client_t client;

  // scanf("%s %s %d %f", name, account_type, &balance, &id);
  gets(name);
  fflush(stdin);
  scanf("%s", account_type);
  fflush(stdin);
  scanf("%lf %d", &balance, &id);

  // printf("%s %s %0.2lf %d\n", name, account_type, balance, id);
  // strcpy(client.name, "ali");
}
void edit_client_data(int client_id)
{
  printf("edit_client_data");
}
void delete_client(int client_id)
{
  printf("delete_client");
}
void print_client_data(int client_id)
{
  printf("print_client_data");
}
void transfer_money(int sender_id, int receiver_id, double amount_of_money)
{
  printf("transfer_money");
}