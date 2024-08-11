#include <bits/stdc++.h>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int numWords = 0;
    cin >> numWords;
    while(numWords--) {
        string word = "";
        cin >> word;
        if (word.length() > 10) {
            cout << word[0] << std::to_string(word.length() - 2) << word[word.length()-1] << "\n";
        } else {
            cout << word << "\n";
        }
    }
}
