#ifndef CLIENT_H
#define CLIENT_H

typedef struct client
{
  char name[50];
  double balance;
  char account_type[7];
  int id;
} client_t;

void create_client(void);
void edit_client_data(int client_id);
void delete_client(int client_id);
void print_client_data(int client_id);
void transfer_money(int sender_id, int receiver_id, double amount_of_money);

#endif
