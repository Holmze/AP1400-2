#include <iostream>
#include <gtest/gtest.h>
#include "bst.h"

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        // debug section
        BST bst{};
        // BST bst2{bst};
        // cout<<"create bst"<<endl;
        bst.add_node(5);
        // cout<<bst.get_root()->value<<endl;
        bst.add_node(4);
        bst.add_node(3);
        bst.add_node(2);
        bst.add_node(1);
        // cout << bst.get_root()->value << endl;
        // cout<<bst<<endl;
        // cout<<bst2<<endl;
        
        // Node node{};
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