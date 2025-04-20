/*************************************************************************
 * @File Name: 713.cpp
 * @Description: 
 * @Author: ppq~
 * @Created Time: Sat Apr 19 20:28:02 2025
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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
        sort(nums.begin(), nums.end());
        for(auto it:nums) {
            cout << it << endl;
        }*/

        int ans = 0;
        int l=0;
        int n = nums.size();
        int prod = 1; 
        for(int i = 0; i < n; i++){
            prod = prod*nums[i];
            while(prod >= k ) {
                prod = prod / nums[l];
                l=l+1;
            }
            ans = ans + (i-l+1);
        }
        return ans;
    }
};

int main()
{   
    vector<int> nums = {10,5,2,6};
    int k = 100;
    Solution solve;
    cout << solve.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}

