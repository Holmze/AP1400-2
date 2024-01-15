#ifndef Q4_H
#define Q4_H
#include <vector>
#include <iostream>

namespace q4{
    using std::cout;
    using std::endl;
    struct Vector2D
    {
    double x{};
    double y{}; 
    };
    struct Sensor
    {
        Vector2D pos;
        double accuracy;    
    };    
    Vector2D kalman_filter(std::vector<Sensor> sensors){
        double totalX = 0.0;
        double totalY = 0.0;
        double accuracy = 0.0;
        for(auto s : sensors){
            accuracy+=s.accuracy;
        }
        for(auto s : sensors){
            totalX += s.pos.x*s.accuracy /accuracy;
            totalY += s.pos.y*s.accuracy /accuracy;
        }
        cout << totalX <<", "<<totalY<<" accu = "<<accuracy<<endl;
        return Vector2D{totalX,totalY};
    }
}
#endif //Q4_H