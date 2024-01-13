#include <iostream>
#include <gtest/gtest.h>
#include <cmath>

#include "q1.h"
#include "q2.h"
#include "q3.h"
#include "q4.h"
// #include<vector>
// #include <string>
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    if (true) // make false to run unit-tests
    {
        // debug section

        // auto min1 = q1::gradient_descent(0.01, 0.1, cos);
        // cout << min1<<endl;
        // min1 = q1::gradient_descent(0.01, 0.01, cos);
        // cout << min1<<endl;

        // std::vector<q2::Patient> patients = q2::read_file("lung_cancer.csv");
        // q2::sort(patients);
        // int i=0;
        // for (const auto& patient : patients) {
        //     std::cout << i << std::endl;
        //     i++;
        //     std::cout << "Name: " << patient.name << std::endl;
        //     std::cout << "Age: " << patient.age << std::endl;
        //     std::cout << "Smokes: " << patient.smokes << std::endl;
        //     std::cout << "AreaQ: " << patient.area_q << std::endl;
        //     std::cout << "Alkhol: " << patient.alkhol << std::endl;
        //     std::cout << std::endl;
        // }
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