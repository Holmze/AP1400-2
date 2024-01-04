#include "client.h"
using std::runtime_error;

Client::Client(std::string id, const Server& server):id(id), server(&server){
    std::string private_key{}, public_key{};
    crypto::generate_key(public_key,private_key);
    this->public_key = public_key;
    this->private_key = private_key;
}

std::string Client::get_id() const{
    return this->id;
}

std::string Client::get_publickey() const{
    return this->public_key;
}

double Client::get_wallet() const{
    Server* b = (Server*)(this->server);
    return b->get_wallet(this->get_id());
}

std::string Client::sign(std::string txt) const{
    return crypto::signMessage(this->private_key, txt);
}

bool Client::transfer_money(std::string receiver, double value){
    std::string transfer = this->get_id()+"-"+receiver+"-"+std::to_string(value);
    std::string signature = sign(this->private_key);
    // cout << transfer <<" & "<<signature<<endl;
    Server* b = (Server*)(this->server);
    try{
        b->add_pending_trx(transfer, signature);
    }
    catch(runtime_error){
        return false;
    }
    return true;
    // if(b->add_pending_trx(transfer, signature)){
    //     // cout<<"add pending trx succ"<<endl;
    //     return true;
    // }
    // else{
    //     // cout<<"add pending trx fail"<<endl;
    //     return false;
    // }
}

int random1num(){
    std::random_device rd;
    std::mt19937 generator(rd());
    // 创建一个分布，范围是 0 到 9
    std::uniform_int_distribution<int> distribution(0, 9);
    // 生成一位随机数字
    return distribution(generator);
}

int random3num(){
    std::random_device rd;
    std::mt19937 generator(rd());
    // 创建一个分布，范围是 0 到 9
    std::uniform_int_distribution<int> distribution(0, 200);
    // 生成一位随机数字
    return distribution(generator);
}

size_t Client::generate_nonce(){
    return (size_t)random3num();
}