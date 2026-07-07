#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0, remainder = 0;
        for (auto &it : nums) {
            sum+=it;
        }
        remainder = sum % k;
        if (remainder == 0) {
            return 0;
        } else if (remainder == sum) {
            return sum;
        } else {
            return remainder;
        }
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> nums = {3, 9, 7};
    int k = 5;
    cout << sol->minOperations(nums, k);
    delete sol;
}
