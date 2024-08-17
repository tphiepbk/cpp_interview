#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string input = "";
    cin >> input;
    if (int(input[0]) >= 97) {
        input[0] = char((int)input[0] - 32);
    }
    cout << input << "\n";
}
