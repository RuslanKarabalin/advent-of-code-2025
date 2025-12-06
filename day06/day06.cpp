#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::vector<std::vector<long long>> vec;
    std::vector<std::string> operations;
    std::string line;
    while (std::getline(std::cin, line)) {
        size_t pos;
        std::string t;
        if (line.starts_with("*") || line.starts_with("+")) {
            while ((pos = line.find(" ")) != std::string::npos) {
                t = line.substr(0, pos);
                if (t != "" && t != " ") {
                    operations.push_back(t);
                }
                line.erase(0, pos + 1);
            }
        } else {
            std::vector<long long> v;
            while ((pos = line.find(" ")) != std::string::npos) {
                t = line.substr(0, pos);
                if (t != "" && t != " ") {
                    v.push_back(std::stoll(t));
                }
                line.erase(0, pos + 1);
            }
            if (line != "" && line != " ") {
                v.push_back(std::stoll(line));
            }
            vec.push_back(v);
        }
    }

    size_t rows = vec.size();
    size_t columns = vec[0].size();

    std::vector<long long> res;
    for (size_t j = 0; j < columns; ++j) {
        long long n;
        if (operations[j] == "+") {
            n = 0;
        } else {
            n = 1;
        }
        for (size_t i = 0; i < rows; ++i) {
            if (operations[j] == "+") {
                n += vec[i][j];
            } else {
                n *= vec[i][j];
            }
        }
        res.push_back(n);
    }

    long long sum = 0;
    for (long long ll : res) {
        sum += ll;
    }

    std::cout << "Result: " << sum << std::endl;
    return 0;
}
