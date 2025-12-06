#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::vector<std::string> grid;
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
            if (line != "" && line != " ") {
                operations.push_back(line);
            }
        } else {
            grid.push_back(line);
        }
    }

    size_t rows = grid.size();
    size_t columns = grid[0].length();

    std::vector<std::vector<long long>> problems;
    std::vector<long long> current_problem;

    for (size_t j = 0; j < columns; ++j) {
        bool all_spaces = true;
        for (size_t i = 0; i < rows; ++i) {
            if (grid[i][j] != ' ') {
                all_spaces = false;
                break;
            }
        }

        if (all_spaces) {
            if (!current_problem.empty()) {
                problems.push_back(current_problem);
                current_problem.clear();
            }
        } else {
            long long n = 0;
            int power = 0;
            for (size_t i = rows; i > 0; --i) {
                char c = grid[i - 1][j];
                if (c != ' ') {
                    n += (c - '0') * std::powl(10, power++);
                }
            }
            current_problem.push_back(n);
        }
    }

    if (!current_problem.empty()) {
        problems.push_back(current_problem);
    }

    std::vector<long long> res;
    for (size_t j = 0; j < operations.size() && j < problems.size(); ++j) {
        long long n;
        if (operations[j] == "+") {
            n = 0;
        } else {
            n = 1;
        }
        for (size_t i = 0; i < problems[j].size(); ++i) {
            if (operations[j] == "+") {
                n += problems[j][i];
            } else {
                n *= problems[j][i];
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
