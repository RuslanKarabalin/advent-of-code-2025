#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int start = 50;
    int password = 0;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::string turn = line.substr(0, 1);
        std::string number = line.substr(1, line.length());
        if (turn == "R") {
            start += std::stoi(number);
        } else {
            start -= std::stoi(number);
        }
        start %= 100;
        if (start < 0) {
            start += 100;
        }
        if (start == 0) {
            ++password;
        }
    }

    std::cout << password << std::endl;
    return 0;
}
