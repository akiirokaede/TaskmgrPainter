#include <cmath>
#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>

int main()
{
    constexpr float PI=3.1416;
    constexpr int count=180;
    int idle[count], busy[count];
    constexpr float delta=2*PI/count;
    float alpha=0;
    for(int i=0;i<count;i++)   
    {   
        busy[i]=count*(sin(alpha)+1)/2;   
        idle[i]=count-busy[i];   
        alpha=alpha+delta;
    }
    int j=0;
    using namespace std::chrono_literals;
    while(true){
        j=j%count;
        auto start = std::chrono::high_resolution_clock::now();
        while(std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()-start)<std::chrono::duration<double, std::milli>(busy[j]));
        std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(idle[j]));
        j++;
    }
}