//
//  main.cpp
//  Regula Falsi Method
//
//  Created by Ali Hussein on 26.12.2023.
//

#include <iostream>
#include <cmath>

double mainFunc(double x){
    return std::pow(x,2) - 2;
}

double newInterval(double a, double b){
    double interv = b - (mainFunc(b) * (b-a)) / (mainFunc(b) - mainFunc(a));
    return interv;
}

double result(double a, double b, double stop){
    double first_interval = 0;
    double stop_cri = 0;
    while(std::abs(b-a)/2 < stop){
        first_interval = newInterval(a,b);
        if(first_interval < 0) a = first_interval;
        else if(first_interval > 0 ) b = first_interval;
        newInterval(a,b);
    }
    return mainFunc(b);
}

int main(){
    double a,b,stop;
    std::cout<<"Enter a: "<<std::endl;
    std::cin>>a;
    std::cout<<"Enter b: "<<std::endl;
    std::cin>>b;
    std::cout<<"Enter stop: "<<std::endl;
    std::cin>>stop;
    std::cout<<result(a,b,stop)<<std::endl;
}

