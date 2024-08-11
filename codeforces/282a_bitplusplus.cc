#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int numOfStatements = 0, x = 0;
    string statement = "";
    cin >> numOfStatements;
    while (numOfStatements--) {
        cin >> statement;
        if (statement[1] == '+') x++;
        else x--;
    }
    cout << x << "\n";
}
