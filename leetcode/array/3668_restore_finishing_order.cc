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
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> result = {};
        for (auto &it : order) {
            if (find(friends.begin(), friends.end(), it) != friends.end()) {
                result.push_back(it);
            }
        }
        return result;
    }
};

int main() {
    Solution* sol = new Solution();
    //vector<int> order = {3, 1, 2, 5, 4};
    //vector<int> friends = {1, 3, 4};
    vector<int> order = {1, 4, 5, 3, 2};
    vector<int> friends = {2, 5};
    vector<int> result = sol->recoverOrder(order, friends);
    printVector(result);
    delete sol;
}
