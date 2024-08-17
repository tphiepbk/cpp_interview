#include <iostream>
#include <string>

using namespace std;

void printOutput(int* arr, int& numPlus) {
    if (arr[0] != 0) {
        cout << "1";
        arr[0]--;
    }
    else if (arr[1] != 0) {
        cout << "2";
        arr[1]--;
    }
    else if (arr[2] != 0) {
        cout << "3";
        arr[2]--;
    }
    if (numPlus != 0) {
        cout << "+";
        numPlus--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    string input = "";
    int numPlus = 0;
    cin >> input;
    int countArr[3] = {0, 0, 0};
    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '+') numPlus++;
        else if (input[i] == '1') countArr[0]++;
        else if (input[i] == '2') countArr[1]++;
        else countArr[2]++;
    }
    for (int i = 0; i < input.length(); i++) {
        printOutput(countArr, numPlus);
    }
    cout << "\n";
}

