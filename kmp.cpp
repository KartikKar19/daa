#include <iostream>
#include <string>
#include <vector>
using namespace std;
void computeLPSArray(string pattern, vector<int>& lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps(m);
    bool found = false;
    computeLPSArray(pattern, lps);
    int i = 0;  // index for text
    int j = 0;  // index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }
        if (j == m) {
            cout << "Pattern found at index: " << i - j << endl;
            found = true;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
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
    KMPSearch(text, pattern);
    return 0;
}