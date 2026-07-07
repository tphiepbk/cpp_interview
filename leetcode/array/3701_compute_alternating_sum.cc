#include <iostream>
#include <vector>
#include "utils.hh"

using namespace std;

class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int res = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) res += nums[i];
            else res -= nums[i];
        }
        return res;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> nums = {1, 3, 5, 7};
    int res = sol->alternatingSum(nums);
    cout << res;
    delete sol;
}
