#include <iostream>
#include <set>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::set<long long> s;
    std::string line;
    while (std::getline(std::cin, line, ',')) {
        std::string::size_type d = line.find('-');
        unsigned long long start = std::stoll(line.substr(0, d));
        unsigned long long end = std::stoll(line.substr(d + 1));
        for (long long i = start; i <= end; ++i) {
            std::string num = std::to_string(i);
            std::cout << "num: " << num << std::endl;
            bool isValid = false;
            for (int l = 1; l < (num.length() / 2) + 1; ++l) {
                std::string sub = num.substr(0, l);
                std::cout << "--sub: " << sub << std::endl;
                for (int j = l; j < num.length(); j += l) {
                    isValid = false;
                    std::string subSub = num.substr(j, l);
                    std::cout << "----subSub: " << subSub << std::endl;
                    if (sub != subSub) {
                        isValid = true;
                        break;
                    }
                }
                if (!isValid) {
                    std::cout << "------INVALID: " << i << std::endl;
                    s.insert(i);
                }
            }
        }
    }
    long long sum = 0;
    for (long long n : s) {
        std::cout << n << std::endl;
        sum += n;
    }
    std::cout << "Result: " << sum << std::endl;
    return 0;
}
