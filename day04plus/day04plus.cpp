#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::vector<std::vector<char>> vector;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::vector<char> v;
        for (char c : line) {
            v.push_back(c);
        }
        vector.push_back(v);
    }
    int num = 0;
    int sum = 0;
    int prevAllSum = 0;
    int allSum = INT_MAX;
    while (prevAllSum != allSum) {
        prevAllSum = allSum;
        allSum = 0;
        for (size_t i = 0; i < vector.size(); ++i) {
            std::vector<char> v = vector[i];
            for (size_t j = 0; j < v.size(); ++j) {
                char ul, uc, ur, l, c, r, dl, dc, dr;
                c = vector[i][j];
                if (c == '@') {
                    if (i == 0) {
                        ul = uc = ur = '.';
                        if (j == 0) {
                            l = dl = '.';
                            r = vector[i][j + 1];
                            dr = vector[i + 1][j + 1];
                            dc = vector[i + 1][j];
                        } else if (j == v.size() - 1) {
                            r = dr = '.';
                            l = vector[i][j - 1];
                            dl = vector[i + 1][j - 1];
                            dc = vector[i + 1][j];
                        } else {
                            l = vector[i][j - 1];
                            r = vector[i][j + 1];
                            dl = vector[i + 1][j - 1];
                            dc = vector[i + 1][j];
                            dr = vector[i + 1][j + 1];
                        }
                    } else if (i == vector.size() - 1) {
                        dl = dc = dr = '.';
                        if (j == 0) {
                            l = ul = '.';
                            r = vector[i][j + 1];
                            ur = vector[i - 1][j + 1];
                            uc = vector[i - 1][j];
                        } else if (j == v.size() - 1) {
                            r = ur = '.';
                            l = vector[i][j - 1];
                            ul = vector[i - 1][j - 1];
                            uc = vector[i - 1][j];
                        } else {
                            l = vector[i][j - 1];
                            r = vector[i][j + 1];
                            ul = vector[i - 1][j - 1];
                            uc = vector[i - 1][j];
                            ur = vector[i - 1][j + 1];
                        }
                    } else {
                        if (j == 0) {
                            ul = l = dl = '.';
                            uc = vector[i - 1][j];
                            ur = vector[i - 1][j + 1];
                            r = vector[i][j + 1];
                            dc = vector[i + 1][j];
                            dr = vector[i + 1][j + 1];
                        } else if (j == v.size() - 1) {
                            ur = r = dr = '.';
                            ul = vector[i - 1][j - 1];
                            uc = vector[i - 1][j];
                            l = vector[i][j - 1];
                            dl = vector[i + 1][j - 1];
                            dc = vector[i + 1][j];
                        } else {
                            ul = vector[i - 1][j - 1];
                            uc = vector[i - 1][j];
                            ur = vector[i - 1][j + 1];
                            l = vector[i][j - 1];
                            r = vector[i][j + 1];
                            dl = vector[i + 1][j - 1];
                            dc = vector[i + 1][j];
                            dr = vector[i + 1][j + 1];
                        }
                    }
                    num = 0;
                    if (ul == '@') {
                        ++num;
                    }
                    if (uc == '@') {
                        ++num;
                    }
                    if (ur == '@') {
                        ++num;
                    }
                    if (l == '@') {
                        ++num;
                    }
                    if (r == '@') {
                        ++num;
                    }
                    if (dl == '@') {
                        ++num;
                    }
                    if (dc == '@') {
                        ++num;
                    }
                    if (dr == '@') {
                        ++num;
                    }
                } else {
                    num = 9;
                }
                if (num < 4) {
                    vector[i][j] = '.';
                    ++sum;
                }
                allSum += num;
            }
        }
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "allSum: " << allSum << std::endl;
        for (std::vector<char> v : vector) {
            for (char c : v) {
                printf("%c", c);
            }
            printf("\n");
        }
    }
    std::cout << "Result: " << sum << std::endl;
    return 0;
}
