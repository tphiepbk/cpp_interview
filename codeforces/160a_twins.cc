#include <algorithm>
#include <functional>
#include <ios>
#include <iostream>

using namespace std;

void printArr(int* arr, int N) {
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int numCoins = 0;
    cin >> numCoins;
    int* coins = new int[numCoins];
    for (int i = 0; i < numCoins; i++) {
        cin >> coins[i];
    }

    sort(coins, coins+numCoins, greater<int>());

    int sum = 0, otherSum = 0;
    for (int i = 0; i < numCoins; i++) {
        sum += coins[i];
        otherSum = 0;
        for (int j = i+1; j < numCoins; j++) {
            otherSum += coins[j];
        }
        if (sum > otherSum) {
            cout << i+1 << "\n";
            break;
        }
    }

    delete[] coins;
    coins = nullptr;
}
