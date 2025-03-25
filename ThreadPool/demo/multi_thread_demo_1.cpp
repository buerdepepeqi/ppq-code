/*************************************************************************
 * @File Name: multi_thread_demo_2.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Sun Mar  9 21:13:02 2025
 ************************************************************************/

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Counter {
public:
    // 默认构造函数
    Counter(int t_value, int t_name) : value(t_value), name(t_name) {
        std::cout << "default" << std::endl;
    }

    // 拷贝构造函数
    Counter(const Counter& other) {
        std::cout << "test copy" << std::endl;
        std::lock_guard<std::mutex> lock(other.mtx);
        value = other.value;
    }

    // 获取计数器的当前值
    int get() const {
        std::lock_guard<std::mutex> lock(mtx);
        return value;
    }

    int get_name() const {
        return name;
    }

private:
    int value;
    int name;
    mutable std::mutex mtx;
};


void test(const Counter &counter) {
    std::cout << counter.get() << std::endl;
};

int main() {
    Counter counter(1, 2);
    test(counter);   


    Counter * counter_new = new Counter{3, 4};
    test(*counter_new);


    Counter counter_xx(counter);
    test(counter_xx);
    return 0;
}
