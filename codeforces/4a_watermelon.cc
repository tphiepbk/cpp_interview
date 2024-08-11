#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int weight = 0;
    cin >> weight;
    bool found = false;
    for (int i = 2; i < weight; i+=2) {
        if ((weight - i) % 2 == 0) {
            found = true;
        }
    }
    if (found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
