
#include <iostream>
#include <gtest/gtest.h>
#include "client.h"
#include "server.h"

void  show_pending_transactions()
 {
 	std::cout  <<  std::string(20, '*') <<  std::endl;
 	for(const  auto& trx : pending_trxs)
 		std::cout << trx <<  std::endl;
 	std::cout  <<  std::string(20, '*') <<  std::endl;
 }

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
        Server server{};
        auto bryan1 = server.add_client("bryan");
        auto bryan2 = server.add_client("bryan");
        auto bryan3 = server.add_client("bryan");
        // show_wallets(server);
        auto holmze = server.add_client("holmze");
        show_wallets(server);
        // std::string public_key = bryan1->get_publickey();
        // cout<<public_key<<endl;
        // public_key = bryan2->get_publickey();
        // cout<<public_key<<endl;
        // public_key = holmze->get_publickey();
        // cout<<public_key<<endl;
        // cout << bryan1->get_id()<<endl;
        // cout << holmze->get_id()<<endl;
        // Server const* p{&server};
        // auto client = p->get_client("no_one");
        // if(client==nullptr){
        //     cout << "client is nullptr" <<endl;
        // }
        // std::string sender{}, receiver{};
        // double value;
        // server.parse_trx("bryan-holmze-0.5", sender, receiver, value);
        // cout << sender << " " << receiver;
        // cout << " "<< value<<endl;
        // bool succ = bryan1->transfer_money("holmze",100);
        // if(succ){
        //     show_wallets(server);
        // }
        // show_pending_transactions();
        // Server server{};
        pending_trxs.clear();
        auto bryan{server.add_client("bryan")};
        auto clint{server.add_client("clint")};
        auto sarah{server.add_client("sarah")};
        bryan->transfer_money("clint", 1);
        clint->transfer_money("sarah", 2.5);
        sarah->transfer_money("bryan", 0.5);
        show_pending_transactions();
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;   
}