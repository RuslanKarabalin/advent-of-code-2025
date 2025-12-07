#include <cstdio>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    std::vector<std::string> grid;
    while (std::getline(std::cin, line)) {
        grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<long long>> dp(rows, std::vector<long long>(cols, 0));
    for (int j = 0; j < cols; ++j) {
        if (grid[0][j] == 'S') {
            dp[0][j] = 1;
            break;
        }
    }
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (dp[i][j] == 0) {
                continue;
            }

            long long paths = dp[i][j];
            char current = grid[i][j];
            if (current == '^') {
                if (i + 1 < rows) {
                    if (j > 0) {
                        dp[i + 1][j - 1] += paths;
                    }
                    if (j + 1 < cols) {
                        dp[i + 1][j + 1] += paths;
                    }
                }
            } else {
                if (i + 1 < rows) {
                    dp[i + 1][j] += paths;
                }
            }
        }
    }


    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            long long p = dp[i][j];
            if (p == 0) { 
                printf("   ");
            } else {
                printf(" %2lld", p);
            }
        }
        printf("\n");
    }

    long long result = 0;
    for (int j = 0; j < cols; ++j) {
        result += dp[rows - 1][j];
    }

    std::cout << result << std::endl;
    return 0;
}
