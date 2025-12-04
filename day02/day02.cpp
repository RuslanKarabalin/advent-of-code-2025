#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    unsigned long long sum = 0;
    std::string line;
    while (std::getline(std::cin, line, ',')) {
        std::string::size_type d = line.find('-');
        unsigned long long start = std::stoll(line.substr(0, d));
        unsigned long long end = std::stoll(line.substr(d + 1));
        for (long long i = start; i <= end; ++i) {
            std::string num = std::to_string(i);
            if (num.length() % 2 == 0) {
                long long partLen = num.length() / 2;
                std::string firstPart = num.substr(0, partLen);
                std::string secondPart = num.substr(partLen);
                if (firstPart == secondPart) {
                    sum += i;
                }
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}
