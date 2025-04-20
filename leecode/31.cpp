/*************************************************************************
 * @File Name: 31.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Sat Apr 19 21:46:33 2025
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

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = n-2;
        while(index >= 0 and nums[index] >= nums[index+1]) {
            index --;
        }    
        //cout << index << endl;
        if(index >= 0) {
            int j = n-1;
            while(nums[j] <= nums[index]) {
                j--;
            }
            swap(nums[index], nums[j]);
        }

        reverse(nums.begin()+index+1, nums.end());
    }
};

int main()
{
    Solution solve;
    vector<int> nums = {1,2,3};
    solve.nextPermutation(nums);
    for(auto it: nums){
        cout << it << endl;
    }
    return 0;
}

