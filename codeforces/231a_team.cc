#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int numOfProblems = 0, numSolvable = 0, temp = 0, count = 0;
    cin >> numOfProblems;
    while (numOfProblems--) {
        count = 0;
        for (int i = 0; i < 3; i++) {
            cin >> temp;
            if (temp) count++;
        }
        if (count >= 2) numSolvable++;
    }
    cout << numSolvable << "\n";
}
