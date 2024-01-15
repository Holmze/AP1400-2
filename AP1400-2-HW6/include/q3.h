#ifndef Q3_H
#define Q3_H
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

namespace q3{
    using std::cout;
    using std::endl;
    struct Flight {
        std::string flight_number;
        double duration;
        int connections;
        double connection_times;
        double price;

        bool operator<(const Flight& other) const {
            size_t weighted_sum = duration + connection_times + 3 * price;
            size_t other_weighted_sum = other.duration + other.connection_times + 3 * other.price;
            return weighted_sum > other_weighted_sum;
        }

        // size_t calculateTotalConnectionTime() const {
        //     size_t total_time = 0;
        //     for (size_t time : connection_times) {
        //         total_time += time;
        //     }
        //     return total_time;
        // }
    };

    std::priority_queue<Flight> gather_flights(const std::string& filename) {
        std::priority_queue<Flight> flights;

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "无法打开文件：" << filename << std::endl;
            return flights;
        }

        std::string line;
        while (std::getline(file, line)) {
            // std::istringstream iss(line);
            Flight flight;
            std::vector<std::string> segments;
            size_t pos = 0;
            while ((pos = line.find("-")) != std::string::npos) {
                std::string segment = line.substr(0, pos);
                segments.push_back(segment);
                line.erase(0, pos + 1);
            }
            segments.push_back(line);


            for (const std::string& segment : segments) {
                size_t colon_pos = segment.find(":");
                if (colon_pos != std::string::npos) {
                    std::string key = segment.substr(0, colon_pos);
                    std::string value = segment.substr(colon_pos + 1);
                    // std::cout << "key= " << key << ", value=" << value << std::endl;
                    if(key == " flight_number") flight.flight_number =value.substr(0,value.find_last_not_of(' ')+1);
                    if(key == " duration"){
                        std::istringstream iss2(value);
                        int hours = 0;
                        int minutes = 0;
                        char unit;
                        int value;

                        while (iss2 >> value >> unit) {
                            if (unit == 'h') {
                                hours += value;
                            } else if (unit == 'm') {
                                minutes += value;
                            }
                        }
                        int totalMinutes = hours * 60 + minutes;
                        flight.duration = static_cast<double>(totalMinutes) / 60.0;
                        // flight.duration = std::stoi(value);
                    }
                    if(key == " connections") flight.connections = std::stoi(value);
                    if(key == " connection_times"){
                        std::istringstream iss(value);
                        std::string token;
                        int hours = 0;
                        int minutes = 0;
                        while (std::getline(iss, token, ',')){
                            std::istringstream iss2(token);
                            

                            char unit;
                            int value;

                            while (iss2 >> value >> unit) {
                                if (unit == 'h') {
                                    hours += value;
                                } else if (unit == 'm') {
                                    minutes += value;
                                }
                            }
                        }
                        int totalMinutes = hours * 60 + minutes;
                        flight.connection_times = static_cast<double>(totalMinutes) / 60.0;
                    }
                    if(key == " price") flight.price = std::stod(value);
                }
            }
            // cout << flight.flight_number << "  ";
            // cout << flight.duration <<"  ";
            // cout << flight.connections <<"  ";
            // cout << flight.connection_times <<"  ";
            // cout << flight.price <<"  ";
            // cout << "weight = " << flight.duration + flight.connection_times + 3 * flight.price<<endl;

            flights.push(flight);
            
        }
        // std::sort(flights.begin(), flights.end());
        return flights;
    }
}
#endif //Q3_H