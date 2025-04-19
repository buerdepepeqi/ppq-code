/*************************************************************************
 * @File Name: zijie.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Fri Apr 18 01:12:30 2025
 ************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void dfs(int target, vector<int>& groups, int current, int& result) {
    if (current >= target) {
      return;
    }
    result = max(current, result);
    for (auto group : groups) {
      dfs(target, groups, current * 10 + group, result);
    }
  }
  int findN(int target, vector<int>& groups) {
    int result = 0;
    for (auto group : groups) {
      dfs(target, groups, group, result);
    }
    return result;
  }
};

int main() {
  vector<int> groups{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int target = 23145;
  int result = 22999;
  Solution s;
  cout << s.findN(target, groups) << endl;
}
