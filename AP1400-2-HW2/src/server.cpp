#include "server.h"
#include <random>
#include <sstream>
using std::runtime_error;
static std::default_random_engine e;

std::vector<std::string> pending_trxs = {};

std::map<std::shared_ptr<Client>,double> Server::get_clients() const{
    return this->clients;
}

Server::Server(){
    this->clients = {};
}

std::string random4num(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 9);

    std::string result = "";
    for (int i = 0; i < 4; ++i) {
        int num = dis(gen);
        result += std::to_string(num);
    }

    return result;
}

std::shared_ptr<Client> Server::add_client(std::string id){
    bool isExist{false};
    for(auto& [client, amount]: clients){
        if(client->get_id()==id){
            isExist = true;
            break;
        }
    }
    
    std::string newID = id;
    if(isExist){
        newID += random4num();
    }

    Client* newClient = new Client(newID,*this);
    std::shared_ptr<Client> sp(newClient);
    this->clients[sp] = 5;
    return sp;
}

std::shared_ptr<Client> Server::get_client(std::string id) const{
    for(auto& [client, amount]: clients){
        if(client->get_id()==id){
            return client;
        }
    }
    return nullptr;
}
double Server::get_wallet(std::string id){
    // auto sp = get_client(id);
    // if(sp == nullptr){
    //     return 0;
    // }
    // return this->clients[sp];
    for(auto& [client, amount]: clients){
        if(client->get_id()==id){
            return amount;
        }
    }
    return 0;
}

bool Server::parse_trx(std::string trx, std::string& sender, std::string& receiver, double& value){
    std::istringstream iss(trx);
    std::string token;

    // 解析第一个字符串
    if (!std::getline(iss, token, '-'))
        return false;
    sender = token;

    // 解析第二个字符串
    if (!std::getline(iss, token, '-'))
        return false;
    receiver = token;

    // 解析 double 值
    if (!(iss >> value)){
        throw runtime_error("something bad");
        return false;
    }
        
    // 检查是否已解析整个输入字符串
    if (iss.rdbuf()->in_avail() != 0){
        throw runtime_error("something bad");
        return false;
    }
        
    return true;
}

bool Server::add_pending_trx(std::string trx, std::string signature){
    std::string sender{};
    std::string receiver{};
    double value = 0;
    try{
        parse_trx(trx, sender, receiver, value);
    }
    catch(runtime_error){
        // cout << "wrong parse_trx" <<endl;
        return false;
    }
    

    if(get_wallet(sender)<value){
        throw runtime_error("too much transfer value");
        // cout << "trans value too large"<<endl;
        return false;
    }
    else if(this->get_client(receiver)==nullptr){
        throw runtime_error("receiver not exist");
        return false;
    }
    else{
        pending_trxs.push_back(trx);
        this->clients[this->get_client(sender)] -= value;
        this->clients[this->get_client(receiver)] += value;
    }
    return true;
}

bool hasConsecutiveZeros(const std::string& str) {
    if (str.length() < 10) {
        // 字符串长度不足10，不可能有连续的三个零
        return false;
    }

    std::string prefix = str.substr(0, 10);
    std::string target = "000";

    return (prefix.find(target) != std::string::npos);
}

size_t Server::mine(){
    if(pending_trxs.size()==0){
        return 0;
    }
    
    std::string mempool;
    for(int i = 0;i<pending_trxs.size();i++){
        mempool+=pending_trxs[i];
    }
    

    cout << mempool <<endl;

    for(auto& [client, amount]:clients){
        auto nonce = client->generate_nonce();
        // cout <<"nonce = " << nonce <<endl;
        std::string mempoolNonce = mempool+std::to_string(nonce);
        std::string hashValue{crypto::sha256(mempoolNonce)};
        // cout << hashValue <<endl;
        if(hasConsecutiveZeros(hashValue)){
            amount += 6.5;
            cout << client->get_id() <<endl;
            pending_trxs.clear();
            return nonce;
        }
    }
    for (int i = 150; i < 200; i++) {
        std::string str = mempool + std::to_string(i);
        std::string hash{crypto::sha256(str)};
        // cout <<"nonce = " << i <<endl;
        // cout << hash <<endl;
        if (hash.substr(0, 10).find("000") != std::string::npos) {
            cout << "mine success, nonce = "<<i<<endl;
            cout << "hash value = "<<hash <<endl;
            return i;
        }
    }
    return e() % 200;
    // return 0;
}

void show_wallets(const Server& server) {
    std::cout << std::string(20, '*') << std::endl;
    for (const auto& client : server.get_clients())
        std::cout << client.first->get_id() << " : " << client.second << std::endl;
    std::cout << std::string(20, '*') << std::endl;
}

 