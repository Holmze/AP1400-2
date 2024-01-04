#ifndef SERVER_H
#define SERVER_H
#include<cstdlib>

#include<map>
#include<iostream>
#include<string>
#include<memory>

#include "client.h"
#include "crypto.h"

using std::cout;
using std::endl;

class Client;

extern std::vector<std::string> pending_trxs;

class Server
{
public:
	Server();
	std::map<std::shared_ptr<Client>,double> get_clients() const;
	std::shared_ptr<Client> add_client(std::string id);
	//This function will create a new Client with the specified id. If this id already exists, the server should add a random 4 digit number at the end of it automatically.
	//::UPDATE:: each client should be assigned with 5 coins at the begining.
	//note. do not use srand for your random numbers.

	std::shared_ptr<Client> get_client(std::string id) const;
	//Using this function you can get a pointer to a Client using its id.

	double get_wallet(std::string id);
	//Using this function will return the wallet value of the client with username id.

	bool parse_trx(std::string trx, std::string& sender, std::string& receiver, double& value);
	//Each transaction has 3 properties: i) id of the sender ii) id of the receiver iii) value of money to transfer. We will show each transaction with a string, concatenating each of these properties with a -. For example if ali sends 1.5 coins to hamed the transaction will be shown by a string "ali-hamed-1.5". This function will parse this string format and outputting each property separately, if the string is not standard you should throw a runtime error.

	bool add_pending_trx(std::string trx, std::string signature);
	//Each Client can add a pending transaction using the transaction format described in the above section. Only accept a pending transaction by authenticating the sender's signature and if he has enough money in his wallet. note. define the below variable outside the Server class and save the pending transactions in it.

	size_t mine();
	/*
	As mentioned in the TA class each transaction has a pending state until it has been mined and to mine transactions you first need to put your pending transactions together: For example if you have 3 transactions like "ali-hamed-1.5", "mhmd-maryam-2.25", and "mahi-navid-0.5"; You will get one final string as: "ali-hamed-1.5mhmd-maryam-2.25mahi-navid-0.5". We call this string the mempool. You will also add a number called nonce at the end of this string. To mine the transactions the server will generate the mempool and asks each Client for a nonce and calculates the sha256 of the final string. For each nonce if the generated sha256 has 4 zeros in a row in the first 10 numbers, then the mine is successful and the client who called the correct nonce will be awarded with 6.25 coins. after a successful mine of the pending transactions, all the transactions will be removed from pending and the effect of them will be applied on the clients.
	::UPDATE:: instead of 4 zeros use 3 zeros in a row so it wont take time for your runs.
	note. after a successful mine, print the id of the miner and return the associate nonce.
	*/

private:
	std::map<std::shared_ptr<Client>, double> clients;//This member variable will map each client to its wallet. The wallet is the amount of money the client has. 
};
void show_wallets(const Server& server);
#endif //SERVER_H