#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n = 0, k = 0, a = 0, count = 0, threshold = -1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (i == k-1) threshold = a;
        if (a >= threshold && a > 0) count++;
    }
    cout << count << "\n";
}
