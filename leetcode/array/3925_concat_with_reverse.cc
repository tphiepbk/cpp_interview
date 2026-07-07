#include <iostream>
#include <vector>
#include <algorithm>

#define printVector(v) \
for (auto& it: v) {\
    cout << it << " ";\
}\
cout << "\n";

using namespace std;

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> result = nums;
        reverse(nums.begin(), nums.end());
        result.insert(result.end(), nums.begin(), nums.end());
        return result;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> nums = {1, 2, 3};
    vector<int> result = sol->concatWithReverse(nums);
    printVector(result);
    delete sol;
}
