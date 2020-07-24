#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>

int main()
{
    unsigned i;
    std::cout<<"请输入目标占用率（1～100）：";
    std::cin>>i;
    if(i<1||i>100){std::cout<<"故意的？";return 1;}
    using namespace std::chrono_literals;
    auto end = std::chrono::duration<double, std::milli>(i*10);
    auto relax = std::chrono::duration<double, std::milli>(1000-(i*10));
    while(true){
        auto start = std::chrono::high_resolution_clock::now();
        while(std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()-start)<end);
        std::this_thread::sleep_for(relax);
    }
}