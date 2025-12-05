#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::vector<std::pair<long long, long long>> vector;
    std::string line;
    std::getline(std::cin, line);
    while (line != "") {
        std::string::size_type d = line.find('-');
        long long start = std::stoll(line.substr(0, d));
        long long end = std::stoll(line.substr(d + 1));

        vector.emplace_back(start, end);

        std::getline(std::cin, line);
    }

    std::sort(vector.begin(), vector.end(),
              [](auto& left, auto& right) { return left.first < right.first; });

    std::vector<std::pair<long long, long long>> unionVector;
    std::pair<long long, long long> cur = vector[0];
    for (size_t i = 1; i < vector.size(); ++i) {
        std::pair<long long, long long> s = vector[i];
        if (s.first <= cur.second) {
            if (s.second > cur.second) {
                cur.second = s.second;
            }
        } else {
            unionVector.push_back(cur);
            cur = s;
        }
    }
    unionVector.push_back(cur);

    int sum = 0;
    while (std::getline(std::cin, line)) {
        long long num = std::stoll(line);

        for (auto v : unionVector) {
            if (v.first <= num && num <= v.second) {
                std::cout << num << std::endl;
                ++sum;
                break;
            }
        }
    }

    std::cout << "Result: " << sum << std::endl;
    return 0;
}
