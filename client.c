#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

client_t bank[MAX_NUMBER_OF_CLIENTS];
// client_t client;
int clientCount = 0;

void create_client(void)
{
  if(clientCount >= MAX_NUMBER_OF_CLIENTS)
  {
    printf("your bank capacity is full, you can't add new client.\n");
  }
  else
  {
    client_t client;
    char name[50] = "\0", account_type[7] = "\0";
    double balance = 0.0f;
    int client_id = 0;

    // scanf("%s %s %d %f", name, account_type, &balance, &id);
    fflush(stdin);
    printf("Enter Client Name: ");
    gets(name);
    fflush(stdin);
    printf("Enter account type ( debit or credit ): ");
    scanf("%s", account_type);
    fflush(stdin);
    printf("Enter The Balance : ");
    scanf("%lf", &balance);
    printf("Enter The client id : ");
    scanf("%d", &client_id);

    // printf("%s %s %0.2lf %d\n", name, account_type, balance, id);
    // strcpy(client.name, "ali");
    strcpy(client.name, name);
    strcpy(client.account_type, account_type);
    client.balance = balance;
    client.id = client_id;

    // printf("client : %s %s %0.2lf %d\n", client.name, client.account_type, client.balance, client.id);
    bank[clientCount++] = client;
    printf(" account created successfully \n");
  }
}

void edit_client_data(void)
{
  client_t client;
  int client_id = 0;
  int i = 0;
  printf("Enter The client id : ");
  scanf("%d", &client_id);

  for(i = 0; i< clientCount; ++i)
  {
    client = bank[i];
    if(client_id == client.id)
    {
      printf("client %d : %s %s %0.2lf %d\n", i,client.name, client.account_type, client.balance, client.id);
      break;
    }
  }
  if(clientCount == i)
  {
    printf("can't found this account in bank.\n");
  }else
  {
    // client founded in position i
    char name[50] = "\0", account_type[7] = "\0";
    double balance = 0.0f;
    int client_id = 0;
    // getting new data section
    fflush(stdin);
    printf("Enter updated Client Name: ");
    gets(name);
    fflush(stdin);
    printf("Enter updated account type ( debit or credit ): ");
    scanf("%s", account_type);
    fflush(stdin);
    printf("Enter The updated Balance : ");
    scanf("%lf", &balance);
    printf("Enter The updated client id : ");
    scanf("%d", &client_id);

    // edit data in struct client
    strcpy(client.name, name);
    strcpy(client.account_type, account_type);
    client.balance = balance;
    client.id = client_id;

    // update data in bank array
    bank[i] = client;

    printf("client account is updated to\n");
    printf("client %d : %s %s %0.2lf %d\n", i,client.name, client.account_type, client.balance, client.id);

  }
}

void delete_client(void)
{
  client_t client;
  int client_id = 0;
  int i = 0;
  printf("Enter The client id : ");
  scanf("%d", &client_id);

  for(i = 0; i< clientCount; ++i)
  {
    client = bank[i];
    if(client_id == client.id)
    {
      printf("client %d : %s %s %0.2lf %d\n", i,client.name, client.account_type, client.balance, client.id);
      break;
    }
  }
  if(clientCount == i)
  {
    printf("can't found this account in bank.\n");
  }else
  {
    // client founded in position i
    for(++i; i < clientCount; ++i)
    {
      bank[i-1] = bank[i];
    }
    clientCount--;
    printf("client account is deleted\n");
  }
}

void print_client_data(void)
{
  client_t client;
  int client_id = 0;
  int i = 0;
  printf("Enter The client id : ");
  scanf("%d", &client_id);

  for(i = 0; i< clientCount; ++i)
  {
    client = bank[i];
    if(client_id == client.id)
    {
      printf("client %d : %s %s %0.2lf %d\n", i,client.name, client.account_type, client.balance, client.id);
      break;
    }
  }
  if(clientCount == i)
  {
    printf("can't found this account in bank.\n");
  }
}

void transfer_money(void)
{
  client_t sender;
  client_t receiver;
  int sender_id;
  int receiver_id;

  int i = 0, j = 0;
  double cash_transfered;
  printf("Enter The sender client id : ");
  scanf("%d", &sender_id);
  printf("Enter The receiver client id : ");
  scanf("%d", &receiver_id);

  // found the sender
  for(i = 0; i< clientCount; ++i)
  {
    sender = bank[i];
    if(sender_id == sender.id)
    {
      printf("sender %d : %s %s %0.2lf %d\n", i,sender.name, sender.account_type, sender.balance, sender.id);
      break;
    }
  }
  if(clientCount == i)
  {
    printf("can't found the sender account in bank.\n");
    return;
  }
  // found the receiver
  for(j = 0; j< clientCount; ++j)
  {
    receiver = bank[j];
    if(receiver_id == receiver.id)
    {
      printf("receiver %d : %s %s %0.2lf %d\n", j,receiver.name, receiver.account_type, receiver.balance, receiver.id);
      break;
    }
  }
  if(clientCount == j)
  {
    printf("can't found the receiver account in bank.\n");
  }
  else
  {
    // start transfer after finding sender and receiver accounts in the bank
    printf("Enter The cash amount you want to tranfer : ");
    scanf("%lf", &cash_transfered);
    if(cash_transfered > 0){
      if(cash_transfered > sender.balance){
        printf(" sender account balance is %0.2lf so you can't transfer %0.2lf from it\n", sender.balance, cash_transfered);
      }
      else
      {
        bank[i].balance -= cash_transfered;
        bank[j].balance += cash_transfered;
        printf(" done transfer \n");
      }
    }
    else
    {
      printf("you can't transfer 0 or negative value\n");
    }
  }
}

void print_all_accounts(void)
{
  client_t client;
  printf("Bank has %d clients\n", clientCount);
  printf("=============================================\n");
  printf("client number | name | account type | balance | id \n");
  for(int i = 0; i < clientCount; ++i)
  {
    client = bank[i];
    printf("client %d | %s | %s | %0.2lf | %d \n", i,client.name, client.account_type, client.balance, client.id);
  }
  printf("=============================================\n");
}
