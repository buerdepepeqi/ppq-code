/*************************************************************************
 * @File Name: multi_thread_demo.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Sun Mar  9 21:04:40 2025
 ************************************************************************/
#include <iostream>
#include <thread>
#include <vector>

// 线程任务函数1
void task1(int id) {
    std::cout << "Thread " << id << " started\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " finished\n";
}

// 线程任务函数2
void task2(const std::string& msg) {
    std::cout << "Message: " << msg << "\n";
}

int main() {
    std::vector<std::thread> threads;
    
    // 创建3个线程
    for (int i=0; i<3; ++i) {
        threads.emplace_back(task1, i);  // 传递参数
    }
    
    // 创建带参数的线程
    std::thread t(task2, "Hello from thread");
    threads.push_back(std::move(t));
    
    // 等待所有线程完成
    for (auto& th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }
    
    return 0;
}

