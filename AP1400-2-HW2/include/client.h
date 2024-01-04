#ifndef CLIENT_H
#define CLIENT_H
#include<string>
#include<iostream>
#include<random>
// #include <sstream>
#include "crypto.h"
#include "server.h"
using std::cout;
using std::endl;

class Server;

class Client
{
public:
	Client(std::string id, const Server& server);
	std::string get_id() const;
	std::string get_publickey() const;
	double get_wallet() const;
	std::string sign(std::string txt) const;
	bool transfer_money(std::string receiver, double value);
	size_t generate_nonce();
private:
	Server const* const server;//指向类型为 Server 的对象，并且该指针本身也是常量，即不可更改指向的对象。
	const std::string id;
	std::string public_key;
	std::string private_key;
};
#endif //CLIENT_H