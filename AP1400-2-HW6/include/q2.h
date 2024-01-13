#ifndef Q2_H
#define Q2_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace q2{
    struct Patient
    {
        std::string name;
        size_t age;
        size_t smokes;
        size_t area_q;
        size_t alkhol;
    };
    std::vector<Patient> read_file(std::string filename){
        std::vector<Patient> patients;
        filename = "/home/chz/AP1400-2/AP1400-2-HW6/resources/"+filename;
        std::ifstream file(filename);
        // std::cout << filename <<std::endl;
        if (!file.is_open()) {
            std::cerr << "Failed to open the file: " << filename << std::endl;
            return patients;
        }
        // std::cout << filename <<std::endl;
        std::string line;

        // 跳过CSV文件的标题行
        // std::cout << filename <<std::endl;
        std::getline(file, line);
        std::getline(file, line);
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string cell;

            Patient patient;
            std::getline(iss, patient.name, ','); // 读取Name字段并存储到name
            std::getline(iss, cell, ','); // 读取Surname字段
            patient.name += " " + cell; // 将Surname合并到name

            std::getline(iss, cell, ','); // 读取Age字段
            patient.age = std::stoi(cell);
            std::getline(iss, cell, ','); // 读取Smokes字段
            patient.smokes = std::stoi(cell);
            std::getline(iss, cell, ','); // 读取AreaQ字段
            patient.area_q = std::stoi(cell);
            std::getline(iss, cell); // 读取Alkhol字段
            patient.alkhol = std::stoi(cell);

            patients.push_back(patient);
        }
        // std::cout << filename <<std::endl;
        // 打印读取的数据
        // for (const auto& patient : patients) {
        //     std::cout << "Name: " << patient.name << std::endl;
        //     std::cout << "Age: " << patient.age << std::endl;
        //     std::cout << "Smokes: " << patient.smokes << std::endl;
        //     std::cout << "AreaQ: " << patient.area_q << std::endl;
        //     std::cout << "Alkhol: " << patient.alkhol << std::endl;
        //     std::cout << std::endl;
        // }
        return patients;
    }
    bool comparePatients(const Patient& p1, const Patient& p2) {
        int score1 = 3 * p1.age + 5 * p1.smokes + 2 * p1.area_q + 4 * p1.alkhol;
        int score2 = 3 * p2.age + 5 * p2.smokes + 2 * p2.area_q + 4 * p2.alkhol;

        return score1 > score2;
    }

    void sort(std::vector<Patient>& patients) {
        std::sort(patients.begin(), patients.end(), comparePatients);
    }
}//namespace q2


#endif //Q2_H