#include <iostream>
#include <vector>

#define printVector(v) \
for (auto& it: v) {\
    cout << it << " ";\
}\
cout << "\n";

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res = {};
        for (auto &ele: nums) {
            if (ele < pivot) res.push_back(ele);
        }
        for (auto &ele: nums) {
            if (ele == pivot) res.push_back(ele);
        }
        for (auto &ele: nums) {
            if (ele > pivot) res.push_back(ele);
        }
        return res;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<int> nums = {9,12,5,10,14,3,10};
    int pivot = 10;
    vector<int> res = sol->pivotArray(nums, pivot);
    printVector(res);
    delete sol;
}
