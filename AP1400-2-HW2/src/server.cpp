#include "server.h"
#include <random>
#include <sstream>
using std::runtime_error;

std::map<std::shared_ptr<Client>,double>> Server::get_clients() const{
    return this->clients;
}

Server::Server(){
    this->client = {};
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

std::shared_ptr<Client> add_client(std::string id){
    bool isExist{false};
    for(auto& [client, amount]: client){
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

std::shared_ptr<Client> get_client(std::string id){
    for(auto& [client, amount]: client){
        if(client->get_id()==id){
            return client;
        }
    }
    return nullptr;
}
double get_wallet(std::string id){
    // auto sp = get_client(id);
    // if(sp == nullptr){
    //     return 0;
    // }
    // return this->clients[sp];
    for(auto& [client, amount]: client){
        if(client->get_id()==id){
            return amount;
        }
    }
    return 0;
}

bool parse_trx(std::string trx, std::string sender, std::string receiver, double value){
    std::istringstream iss(input);
    std::string token;

    // 解析第一个字符串
    if (!std::getline(iss, token, '-'))
        return false;
    str1 = token;

    // 解析第二个字符串
    if (!std::getline(iss, token, '-'))
        return false;
    str2 = token;

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

bool add_pending_trx(std::string trx, std::string signature){
    std::string sender{};
    std::string receiver{};
    double value = 0;
    try{
        parse_trx(trx, sender, receiver, value);
    }
    catch(runtime_error){
        return false;
    }
    pending_trxs.push_back(trx);

    if(get_wallet(sender)<value){
        return false;
    }
    else{
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

size_t mine(){
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
        std::string mempoolNonce = mempool+nonce;
        std::string hashValue{crypto::sha256(mempoolNonce)};
        if(hasConsecutiveZeros(hashValue)){
            amount += 6.5;
            cout << get_id(client) <<endl;
            pending_trxs.clear();
            return nonce;
        }
    }
    return 0;
}

void show_wallets(const Server& server) {
    std::cout << std::string(20, '*') << std::endl;
    for (const auto& client : server.get_clients())
        std::cout << client.first->get_id() << " : " << client.second << std::endl;
    std::cout << std::string(20, '*') << std::endl;
}

