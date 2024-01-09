#include <iostream>
#include <gtest/gtest.h>
#include "unique_ptr.h"
#include "shared_ptr.h"

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
        // UniquePtr<int> ptr{new int{10}};
        // // cout << *ptr <<endl;
        // auto up = make_unique<int>(42);

        // UniquePtr<int> ptr1;
        // cout << ptr.get() <<endl;
        // cout << *ptr <<endl;
        // UniquePtr<std::string> sptr{new std::string{"hello"}};
        // cout << sptr->length() <<endl;
        // // UniquePtr<std::string> ptr(new std::string("hello"));
        // sptr.reset(new std::string("nice"));
        // std::cout << *sptr << std::endl;  // 输出：nice

        // UniquePtr<double> dptr{new double{1.567}};
        // double *tmp{dptr.release()};
        // std::cout << *tmp << std::endl; // output: 1.567
        // delete tmp; // manual deletion

        // UniquePtr<int> ptr1{make_unique<int>(10)};
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