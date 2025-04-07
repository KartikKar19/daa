#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min(int a, int b) {
    return (a < b) ? a : b;
}

int assemblyLineScheduling(int n, vector<vector<int>>& a, vector<vector<int>>& t, vector<int>& e, vector<int>& x) {
    vector<int> T1(n), T2(n);

    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];

    for (int i = 1; i < n; i++) {
        T1[i] = min(T1[i-1] + a[0][i], T2[i-1] + t[1][i-1] + a[0][i]);
        T2[i] = min(T2[i-1] + a[1][i], T1[i-1] + t[0][i-1] + a[1][i]);
    }

    return min(T1[n-1] + x[0], T2[n-1] + x[1]);
}

int main() {
    int n;
    cout << "Enter number of stations: ";
    cin >> n;

    vector<vector<int>> a(2, vector<int>(n));
    vector<vector<int>> t(2, vector<int>(n-1));
    vector<int> e(2), x(2);

    cout << "Enter processing times for line 1: ";
    for (int i = 0; i < n; i++) cin >> a[0][i];

    cout << "Enter processing times for line 2: ";
    for (int i = 0; i < n; i++) cin >> a[1][i];

    cout << "Enter transfer times from line 1 to line 2: ";
    for (int i = 0; i < n-1; i++) cin >> t[0][i];

    cout << "Enter transfer times from line 2 to line 1: ";
    for (int i = 0; i < n-1; i++) cin >> t[1][i];

    cout << "Enter entry times for line 1 and line 2: ";
    cin >> e[0] >> e[1];

    cout << "Enter exit times for line 1 and line 2: ";
    cin >> x[0] >> x[1];

    int result = assemblyLineScheduling(n, a, t, e, x);
    cout << "Minimum time to assemble the product: " << result << endl;

    return 0;
}