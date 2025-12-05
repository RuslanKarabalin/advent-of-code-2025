#include <climits>
#include <cmath>
#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    long long sum = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        int lineLength = line.length();
        int lastPos = 0;
        long long num = 0;
        for (int i = 12; i > 0; --i) {
            int remainLength = lineLength - i + 1;
            long long max = LONG_LONG_MIN;
            for (int j = lastPos; j < remainLength; ++j) {
                int ic = line[j] - '0';
                if (ic > max) {
                    max = ic;
                    lastPos = j + 1;
                }
            }
            num += max * std::powl(10, i - 1);
        }
        std::cout << num << std::endl;
        sum += num;
    }

    std::cout << "Result: " << sum << std::endl;
    return 0;
}
