//GRAPHCOLOURING

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& color, int c) {
    for (int u = 0; u < graph.size(); u++) {
        if (graph[v][u] && color[u] == c) {
            return false;
        }
    }
    return true;
}

bool solveGraphColoring(const vector<vector<int>>& graph, vector<int>& color, int m, int v) {
    int n = graph.size();
    if (v == n) {
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (solveGraphColoring(graph, color, m, v + 1)) {
                return true;
            }

            color[v] = 0;
        }
    }

    return false;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices in the graph: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Enter the adjacency matrix (1 if edge exists, 0 otherwise):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the number of colors available: ";
    cin >> m;

    vector<int> color(n, 0);

    if (solveGraphColoring(graph, color, m, 0)) {
        cout << "Solution exists. The color assignments are:" << endl;
        for (int i = 0; i < n; i++) {
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
        }
    } else {
        cout << "Solution does not exist with " << m << " colors." << endl;
    }

    return 0;
}


//NQUEENS
#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}
void solveNQueens(vector<vector<int>>& board, int row, int N) {
    if (row == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1, N);
            board[row][col] = 0;
        }
    }
}

int main() {
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));

    cout << "Solutions for " << N << "-Queens problem:" << endl;
    solveNQueens(board, 0, N);

    return 0;
}


//SUBSETSUMM
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
