#include <iostream>
#include <vector>

using namespace std;

// Function to generate Pascal's Triangle
void generatePascalsTriangle(int numRows) {
    vector<vector<int>> triangle(numRows);

    for (int i = 0; i < numRows; i++) {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;

        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    // Print Pascal's Triangle
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    generatePascalsTriangle(numRows);

    return 0;
}
