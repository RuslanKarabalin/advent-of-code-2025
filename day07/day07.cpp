#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    std::vector<std::vector<char>> grid;
    int i = 0;
    while (std::getline(std::cin, line)) {
        std::vector<char> currentLine;
        for (int j = 0; j < line.length(); ++j) {
            char c = line[j];
            if (i == 0) {
                currentLine.push_back(c);
            } else {
                std::vector<char> prevLine = grid[i - 1];
                char prevChar = prevLine[j];
                if (prevChar == 'S') {
                    currentLine.push_back('|');
                    grid[i - 1][j] = '.';
                } else if (prevChar == '|') {
                    if (c == '^') {
                        if (j > 0) {
                            currentLine[j - 1] = '|';
                        }
                        currentLine.push_back('^');
                        ++j;
                        if (j < line.length()) {
                            currentLine.push_back('|');
                        }
                    } else {
                        currentLine.push_back('|');
                    }
                } else {
                    if (currentLine.size() < line.length()) {
                        currentLine.push_back(c);
                    }
                }
            }
        }
        grid.push_back(currentLine);
        ++i;
    }

    for (auto v : grid) {
        for (auto c : v) {
            printf("%c", c);
        }
        printf("\n");
    }

    int result = 0;
    for (size_t i = 1; i < grid.size() - 1; i += 2) {
        std::vector<char> v0 = grid[i];
        std::vector<char> v1 = grid[i + 1];
        for (size_t k = 0; k < v1.size(); ++k) {
            char c0 = v0[k];
            char c1 = v1[k];
            if (c0 == '|' && c1 == '^') {
                ++result;
            }
        }
    }
    std::cout << "Result: " << result << std::endl;
    return 0;
}
