#include <ios>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string input = "";
    cin >> input;
    char currentPlayer;
    int count = 0;
    bool found = false;
    for (size_t i = 0; i < input.length(); i++) {
        if (i == 0) {
            currentPlayer = input[i];
            count++;
        } else {
            if (input[i] == currentPlayer) {
                count++;
            } else {
                count = 1;
                currentPlayer = input[i];
            }
        }
        if (count >= 7) {
            cout << "YES\n";
            found = true;
            break;
        }
    }
    if (!found) cout << "NO\n";
}
