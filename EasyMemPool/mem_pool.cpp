/*************************************************************************
 * @File Name: mem_pool.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Thu Mar  6 00:42:10 2025
 ************************************************************************/
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <functional>

using namespace std;
class MemoryPool {
public:
    MemoryPool(size_t blockSize, size_t initialBlockCount)
        : blockSize(blockSize), head(nullptr) {
        for (size_t i = 0; i < initialBlockCount; ++i) {
            char* newBlock = new char[blockSize];
            reinterpret_cast<Block*>(newBlock)->next = head;
            head = reinterpret_cast<Block*>(newBlock);
        }
    }

    ~MemoryPool() {
        while (head) {
            Block* temp = head;
            head = head->next;
            delete[] reinterpret_cast<char*>(temp);
        }
    }

    void* allocate() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!head) {
            // 空闲链表为空，申请新的内存块
            char* newBlock = new char[blockSize];
            return newBlock;
        }
        Block* block = head;
        head = head->next;
        return block;
    }

    void deallocate(void* ptr) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!ptr) return;
        reinterpret_cast<Block*>(ptr)->next = head;
        head = reinterpret_cast<Block*>(ptr);
    }

private:
    struct Block {
        Block* next;
    };

    size_t blockSize;
    Block* head;
    std::mutex mutex_;
};

int main()
{
    MemoryPool pool(1024, 10); // 每个内存块1024字节，初始10个块
    void* ptr1 = pool.allocate();
    void* ptr2 = pool.allocate();
    pool.deallocate(ptr1);
    void* ptr3 = pool.allocate();
    pool.deallocate(ptr2);
    pool.deallocate(ptr3);
    return 0;
    return 0;
}

