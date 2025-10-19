#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
        int i = n - 1;
        int j = 0;
        int num = 0;
        while(i >= 0 && j < n) {
            if(matrix[i][j] <= mid) {
                num += i+1;
                j++;
            } else {
                i--;
            }
        }
        return num >= k;
    }


    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while(left < right) {
            int mid = (left+right) >> 1;
            cout << left << "," << right << "," <<mid << endl;
            if(check(matrix, mid, k, n)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {-5, 4},
        {-5,4}
    };

    for (const auto &raw: matrix) {
        for(int val : raw){
            cout << val << ", ";
        }
        cout << endl;
    }
    int k = 2;
    Solution *sol = new Solution();
    int res = sol->kthSmallest(matrix, k);
    cout << res << endl;
}
