
#ifndef CLIENT_H
#define CLIENT_H

#define MAX_NUMBER_OF_CLIENTS 3



typedef struct client
{
  char name[50];
  double balance;
  char account_type[7];
  int id;
} client_t;

void create_client(void);
void edit_client_data(void);
void delete_client(void);
void print_client_data(void);
void transfer_money(void);
void print_all_accounts(void);

/*
client_t create_client(void);
void edit_client_data(int client_id);
void delete_client(int client_id);
void print_client_data(int client_id);
void transfer_money(int sender_id, int receiver_id, double amount_of_money);
void print_all_accounts(void);
*/
#endif
