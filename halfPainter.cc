#include <iostream>
#include <chrono>
#include <thread>
#include <iostream>

int main()
{
    using namespace std::chrono_literals;
    while(true){
        auto start = std::chrono::high_resolution_clock::now();
        while(std::chrono::duration<double, std::milli>(std::chrono::high_resolution_clock::now()-start)<500ms);
        std::this_thread::sleep_for(500ms);
    }
}