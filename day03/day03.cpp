#include <climits>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <print>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int sum = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        int firstMax = INT_MIN;
        int firstIndex = 0;
        for (int i = 0; i < line.length() - 1; ++i) {
            int n = line[i] - '0';
            if (n > firstMax) {
                firstMax = n;
                firstIndex = i;
            }
        }
        int secondMax = INT_MIN;
        for (int i = firstIndex + 1; i < line.length(); ++i) {
            int n = line[i] - '0';
            if (n > secondMax) {
                secondMax = n;
            }
        }
        sum += (firstMax * 10) + secondMax;
    }
    std::cout << sum << std::endl;
    return 0;
}
