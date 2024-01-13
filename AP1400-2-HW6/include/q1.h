#ifndef Q1_H
#define Q1_H
#include <iostream>
#include <cmath>
#include <functional>
using std::cout;
using std::endl;

namespace q1{
    template<typename T,typename Func>
    T gradient_descent(T initial_value, T step_size, Func math_function){
        T current_value = initial_value;
        double df { (math_function(current_value + 0.00001) - math_function(current_value)) / 0.00001 };
        
        while(std::abs(df)>1e-6){
            // cout << "Func("<<current_value<<")="<<math_function(current_value) <<endl;
            current_value -= step_size*df;
            df = (math_function(current_value + 0.00001) - math_function(current_value)) / 0.00001;
        }
        return current_value;
    }
    template<typename T,typename Func>
    T gradient_descent(T initial_value, T step_size){
        return gradient_descent(initial_value, step_size, Func());
    }
};

#endif //Q1_H