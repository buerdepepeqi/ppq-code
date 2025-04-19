/*************************************************************************
 * @File Name: git_merge.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Sat Apr 19 16:23:37 2025
 ************************************************************************/

/*
## 问题描述
作为版本控制系统的核心开发者，你需要编写一个功能来
合并多个Git分支的提交历史记录。每个分支的提交已经
按时间戳升序排列，需要将它们合并成一个全局有序的
时间线视图，用于可视化项目的完整历史。

合并规则：
1. 按提交时间戳升序排列
2. 时间戳相同时，按作者ID的字典序升序排列

## 输入格式
- 一个 vector<vector<Commit>> 类型的输入，
其中每个内部 vector<Commit> 表示一个分支已排序的提交记录。
- Commit 结构体定义如下：
struct Commit {
int timestamp;
string author_id;
};

## 输出格式
返回合并后的 vector<Commit>，满足上述排序规则。

## 要求
- 必须使用分治合并（Merge Sort 的分治思想），
即两两合并列表，直到所有列表合并为一个。
- 禁止直接调用库函数（如 std::sort）或使用优先队列（堆）。
- 时间复杂度需为 O(N log K)（N 为总提交数，K 为分支数量）。

## 示例
输入:
[
[ {100, "alice_dev"}, {200, "bob_dev"}, {300, "charlie_dev"} ],
[ {150, "zoe_dev"}, {200, "alice_dev"}, {250, "david_dev"} ],
[ {200, "bob_dev"}, {400, "eve_dev"} ]
]

输出:
[
{100, "alice_dev"}, {150, "zoe_dev"}, {200, "alice_dev"}, {200, "bob_dev"}, {200, "bob_dev"},
{250, "david_dev"}, {300, "charlie_dev"}, {400, "eve_dev"}
]
*/
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

struct Commit {
    int timestamp;
    string author_id;
    Commit(int time, string auth): timestamp(time),author_id(auth){};
};

vector<Commit> mergeTowList(vector<Commit> a, vector<Commit> b) {
    vector<Commit> result;
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
        if(a[i].timestamp < b[j].timestamp) {
            result.push_back(a[i]);
            i++;
        } else if (a[i].timestamp > b[j].timestamp) {
            result.push_back(b[j]);
            j++;
        } else {
            if(a[i].author_id <= b[j].author_id) {
                result.push_back(a[i]);
                i++;
            } else {
                result.push_back(b[j]);
                j++;
            }
        }
    }

    while(i < a.size()) {
        result.push_back(a[i]);
        i++;
    }

    while(j < b.size()){
        result.push_back(b[j]);
        j++;
    }
    return result;
}

vector<Commit> mergeSort(vector<vector<Commit>>& vec) {
    if(vec.empty()) return {};
    if(vec.size()==1) return vec[0];
    int mid = vec.size() / 2;
    vector<vector<Commit>> left(vec.begin(), vec.begin()+mid);
    vector<vector<Commit>> right(vec.begin()+mid, vec.end());
    cout << "mid:" << mid << endl;
    vector<Commit> merge_left = mergeSort(left);
    vector<Commit> merge_right = mergeSort(right);
    cout << "left: " << endl;
    for(auto &cm: merge_left){
        cout << cm.timestamp << ", " << cm.author_id << endl;
    }
    cout << "right" << endl;
    for(auto &cm: merge_right){
        cout << cm.timestamp << ", " << cm.author_id << endl;
    }
    cout <<  "merge111" << endl;
    return mergeTowList(merge_left, merge_right);
}   


int main()
{
    /*
     * [
     [ {100, "alice_dev"}, {200, "bob_dev"}, {300, "charlie_dev"} ],
     [ {150, "zoe_dev"}, {200, "alice_dev"}, {250, "david_dev"} ],
     [ {200, "bob_dev"}, {400, "eve_dev"} ]
     ]
     */

    vector<vector<Commit>> vec = {
        {{100,"alice_dev"},{200, "bob_dev"},{300, "charlie_dev"}},
        {{150, "zoe_dev"}, {200, "alice_dev"}, {250, "david_dev"}},
        {{200, "bob_dev"}, {400, "eve_dev"}} 
    };
     
    for(auto &v1:vec) {
        for(auto cm:v1){
            cout << cm.timestamp << ", " << cm.author_id << endl;
        }
    }
    
    cout << "**************" << endl; 
    vector<Commit> res = mergeSort(vec);

    cout << "**************" << endl; 
    for(auto &cm:res){
        cout << cm.timestamp << ", " << cm.author_id << endl;
    }
    
 
    return 0;
}

