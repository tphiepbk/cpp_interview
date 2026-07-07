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
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (string& ele: operations) {
            if (ele.find("--") != string::npos) {
                res--;
            } else {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution* sol = new Solution();
    vector<string> operations = {"X++","++X","--X","X--"};
    int result = sol->finalValueAfterOperations(operations);
    cout << result;
    delete sol;
}
