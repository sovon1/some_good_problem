#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
long long ps[N][N];

int main() {
    int n;
    cin >> n;
    int arr[n][n];

    // Input the array
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    // Compute the prefix sum array
    // ps[i][j] will store the sum of elements in the submatrix from (1,1) to (i,j)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ps[i][j] = arr[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
        }
    }

    // Apply Kadane's algorithm to find the maximum sum submatrix
    long long maxSum = LLONG_MIN;
    for (int left = 1; left <= n; left++) {
        for (int right = left; right <= n; right++) {
            vector<long long> temp(n + 1, 0);
            for (int i = 1; i <= n; i++) {
                temp[i] = ps[i][right] - ps[i][left - 1];
            }
            // Apply Kadane's algorithm on temp array
            long long currentSum = 0;
            long long bestSum = LLONG_MIN;
            for (int i = 1; i <= n; i++) {
                currentSum += temp[i];
                if (currentSum > bestSum) {
                    bestSum = currentSum;
                }
                if (currentSum < 0) {
                    currentSum = 0;
                }
            }
            maxSum = max(maxSum, bestSum);
        }
    }

    cout << "Maximum sum submatrix: " << maxSum << endl;

    return 0;
}
