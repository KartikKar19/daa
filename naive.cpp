#include <iostream>
#include <string>
using namespace std;
void naiveStringMatch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    bool found = false;
    for (int i = 0; i <= n - m; i++) {
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            cout << "Pattern found at index: " << i << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Pattern not found in text" << endl;
    }
}
int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search for: ";
    getline(cin, pattern);
    cout << "\nSearching for pattern..." << endl;
    naiveStringMatch(text, pattern);
    return 0;
}