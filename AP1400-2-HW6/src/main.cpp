#include <iostream>
#include <gtest/gtest.h>
#include <cmath>

// #include "q1.h"
// #include "q2.h"
// #include "q3.h"
// #include "q4.h"
// #include<vector>
// #include <string>
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
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

        // auto flights = q3::gather_flights("flights.txt");
        // std::vector<std::string> flight_numbers;
        // while (!flights.empty()) 
        // {
        //     flight_numbers.push_back(flights.top().flight_number);
        //     flights.pop();
        // }
        // // std::vector<std::string> correct{"9725", "QR720", "MA127", "9724", "QR492", "GH758"};
        // for(int i=0;i<flight_numbers.size();i++){
        //     cout << flight_numbers[i] <<endl;
        // }
        
        // // std::vector<q4::Sensor> sensors{{{0, 0.01}, 0.5},{{0.5, 0.009}, 0.2}};
        // std::vector<q4::Sensor> sensors1{{{1.23, 0.46}, 0.8},{{1, 0.3}, 0.5},{{0.84, 0.65}, 0.4},{{0.92, 0.5}, 0.2},{{2.01, 0.101}, 0.1}};
        // // std::vector<q4::Sensor> sensors2{{{2.01, 0.101}, 0.1},{{0.92, 0.5}, 0.2},{{0.84, 0.65}, 0.4},{{1, 0.3}, 0.5},{{1.23, 0.46}, 0.8}};
        // auto kalman1{q4::kalman_filter(sensors1)};
        // cout << kalman1.x-1.102<<",,,"<<kalman1.y-0.4440<<endl;
        // // auto kalman2{q4::kalman_filter(sensors2)};
        // // cout << kalman2.x-1.102<<",,,"<<kalman2.y-0.4440<<endl;
        
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