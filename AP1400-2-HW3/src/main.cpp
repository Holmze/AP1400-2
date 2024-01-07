#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        BST bst{};
        bst.add_node(25);
        bst.add_node(10);
        bst.add_node(50);
        bst.add_node(65);
        bst.add_node(60);
        bst.add_node(70);
        bst.add_node(5);
        bst.add_node(2);
        bst.add_node(7);
        bst.add_node(75);
        bst.add_node(20);
        bst.add_node(15);
        // bst.add_node(6);
        // bst.add_node(8);
        
        cout << bst <<endl;
        bst.delete_node(10); // only left child
        cout << bst <<endl;
        

        // debug section
        // BST bst{};
        // // BST bst2{bst};
        // // cout<<"create bst"<<endl;
        // // bst.add_node(5);
        // // bst.add_node(3);
        // // bst.add_node(8);
        // // bst.add_node(1);
        // // bst.add_node(4);
        // // bst.add_node(7);
        // // bst.add_node(9);
        // // bst.add_node(6);

        // bst.add_node(2);
        // bst.add_node(1);
        // bst.add_node(5);
        // bst.add_node(3);
        // bst.add_node(4);
        // bst.add_node(6);
        // // bst.add_node(6);
        // // bst.add_node(6);
        // // bst.add_node(6);
        


        // // // BST::Node** target = bst.find_node(7);
        // // // BST::Node* target_node = *target;
        // // // cout << **bst.find_node(7) <<endl;
        // // // cout << target_node <<endl;
        // // // cout << *target <<endl;
        // // // cout << **target <<endl;
        // // cout << **bst.find_node(5) <<endl<<endl;
        // // cout << **bst.find_node(8) <<endl<<endl;
        // // cout << **bst.find_node(7) <<endl<<endl;
        // // cout << **bst.find_node(9) <<endl<<endl;
        // // // cout << **bst.find_node(7) <<endl;
        // // bst.bfs(printNodeValue);
        // // cout << bst.length()<<endl;
        // // cout << **bst.find_parrent(9) <<endl<<endl;
        // // cout << **bst.find_parrent(6) <<endl<<endl;

        // // cout << "successor of 5 is: "<<endl<<**bst.find_successor(5) <<endl<<endl;
        // // cout << "successor of 3 is: "<<endl<<**bst.find_successor(3) <<endl<<endl;
        // // cout << "successor of 8 is: "<<endl<<**bst.find_successor(8) <<endl<<endl;
        // // cout << "successor of 7 is: "<<endl<<**bst.find_successor(7) <<endl<<endl;
        // // // cout << "successor of 9 is: "<<endl<<**bst.find_successor(9) <<endl<<endl;
        // // // cout << "successor of 10 is: "<<endl<<**bst.find_successor(10) <<endl<<endl;
        // // bst.bfs(printNodeValue);
        // cout<<bst<<endl;
        // cout <<endl;
        // // bst.delete_node(6);
        // // cout<<bst<<endl;
        // // bst.bfs(printNodeValue);
        // // cout <<endl;
        
        // bst.delete_node(2);
        // cout<<bst<<endl;
        // // bst.bfs(printNodeValue);
        // cout <<endl;

        // // bst++
        // cout<<bst++<<endl;
        // cout <<endl;
        // cout<<++bst<<endl;
        // cout <<endl;
        // // bst.find_node(10);
        
        
        // // cout << bst.get_root()->value << endl;
        // // cout<<bst<<endl;
        // // cout<<bst2<<endl;
        // BST bst2{3, 2, 100, 20, 8, 50, 4, 60, 44, 23};
        // cout<<bst2<<endl;
        // cout <<endl;
        // // Node node{};
        
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