/*************************************************************************
 * @File Name: zijie.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Fri Apr 18 01:12:30 2025
 ************************************************************************/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct compare {
    bool operator()(int a, int b) {
        return a > b; // 定义最小堆
    }
};  
class Solution {
 public:
    vector<int> get_topk(const vector<vector<int>> matrix, int k){
        vector<int> res = {};
        priority_queue <int, std::vector<int>, compare> q = {};
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i = 0; i < k; i++){
            q.push(matrix[0][i]);
        }
        cout << n  <<  ", " << m << endl;
        for(int i = 1; i < n ; i++) {
            for(int j = 0; j < k; j++){
                int val = q.top();
                if(matrix[i][j] > val) {
                    q.pop();
                    q.push(matrix[i][j]);
                } else {
                    break;
                }
            }
        }

        while(!q.empty()) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {3,2,1},
        {6,5,4},
        {9,2,1}
    };

    for (const auto &raw: matrix) {
        for(int val : raw){
            cout << val << ", ";
        }
        cout << endl;
    }
    int k = 2;
    Solution *sol = new Solution();
    vector<int> res = sol->get_topk(matrix, k);
    for(const auto &it : res) {
        cout << it << ", ";
    }
    cout << endl;
}
