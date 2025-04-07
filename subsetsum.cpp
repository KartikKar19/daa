#include <iostream>
#include <vector>
using namespace std;
void printSubset(vector<int>& subset) {
    for (int num : subset) {
        cout << num << " ";
    }
    cout << endl;
}
void findSubsets(vector<int>& arr, vector<int>& subset, int index, int target) {
    int sum = 0;
    for (int num : subset) {
        sum += num;
    }
    if (sum == target) {
        printSubset(subset);
        return;
    }
    if (sum > target || index >= arr.size()) {
        return;
    }
    subset.push_back(arr[index]);
    findSubsets(arr, subset, index + 1, target);
    subset.pop_back();
    findSubsets(arr, subset, index + 1, target);
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<int> subset;
    cout << "Subsets with sum " << target << " are:" << endl;
    findSubsets(arr, subset, 0, target);

    return 0;
}