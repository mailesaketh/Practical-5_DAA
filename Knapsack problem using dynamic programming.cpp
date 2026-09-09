#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, W;
    std::cout << "Enter number of items: ";
    std::cin >> n;

    std::vector<int> weights(n), values(n);
    std::cout << "Enter weights of items: ";
    for (int i = 0; i < n; ++i) std::cin >> weights[i];

    std::cout << "Enter values of items: ";
    for (int i = 0; i < n; ++i) std::cin >> values[i];

    std::cout << "Enter Knapsack capacity: ";
    std::cin >> W;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    std::cout << "\nMaximum value possible = " << dp[n][W] << "\n";

    return 0;
}
