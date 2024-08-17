#include <iostream>

using namespace std;

#define M 5
#define N 5

int main() {
    ios_base::sync_with_stdio(false);
    int element = 0, X = 0, Y = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> element;
            if (element == 1) {
                X = i;
                Y = j;
                break;
            }
        }
    }
    if (X >= 2) X-=2;
    else X=2-X;
    if (Y >= 2) Y-=2;
    else Y=2-Y;
    cout << X + Y << "\n";
}
