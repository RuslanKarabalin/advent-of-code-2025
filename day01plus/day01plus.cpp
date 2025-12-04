#include <iostream>
#include <string>

long long floor_div(long long x, long long d) {
    if (d < 0) {
        x = -x;
        d = -d;
    }
    if (x >= 0)
        return x / d;
    return -((-x + d - 1) / d);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    long long start = 50;
    long long password = 0;
    std::string line;

    while (std::getline(std::cin, line)) {
        std::string turn = line.substr(0, 1);
        long long number = std::stoll(line.substr(1));
        long long prevStart = start;

        if (turn == "R") {
            start += number;
            password += floor_div(start, 100) - floor_div(prevStart, 100);
        } else {
            start -= number;
            password +=
                floor_div(prevStart - 1, 100) - floor_div(start - 1, 100);
        }

        start = ((start % 100) + 100) % 100;
    }

    std::cout << password << '\n';
    return 0;
}
