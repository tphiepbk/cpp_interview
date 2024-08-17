#include <iostream>
#include <string>

using namespace std;

#define M 5
#define N 5

int main() {
    ios_base::sync_with_stdio(false);
    string a = "", b = "";
    int tempA = 0, tempB = 0, result = 0;
    cin >> a >> b;
    for (size_t i = 0; i < a.length(); i++) {
        tempA = (int)a[i];
        tempB = (int)b[i];
        if (tempA >= 97) tempA -= 32;
        if (tempB >= 97) tempB -= 32;
        if (tempA > tempB) {
            result = 1;
            break;
        } else if (tempA < tempB) {
            result = -1;
            break;
        }
    }
    cout << result << "\n";
}

