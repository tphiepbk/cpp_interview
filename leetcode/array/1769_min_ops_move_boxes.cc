#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include "utils.hh"

using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res = {};
        for (int i = 0; i < boxes.size(); i++) {
            int steps = 0;
            for (int j = 0; j < boxes.size(); j++) {
                if (j == i) continue;
                if (boxes[j] == '1') steps += abs(i - j);
            }
            res.push_back(steps);
        }
        return res;
    }
};

int main() {
    Solution* sol = new Solution();
    string boxes = "110";
    vector<int> res = sol->minOperations(boxes);
    printVector(res);
    delete sol;
}
