#include <climits>
#include <cmath>
#include <iostream>
#include <vector>

struct Point {
    int x, y;

    bool operator==(const Point& other) {
        return other.x == this->x && other.y == this->y;
    }

    double distanceTo(const Point& other) {
        int dX = this->x - other.x;
        int dY = this->y - other.y;
        return std::sqrt(dX * dX + dY * dY);
    }

    long long getArea(const Point& other) {
        long long dX = std::abs(this->x - other.x) + 1;
        long long dY = std::abs(this->y - other.y) + 1;
        return dX * dY;
    }
};

std::vector<std::string> split(std::string& stringToSplit,
                               const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = stringToSplit.find(delimiter)) != std::string::npos) {
        token = stringToSplit.substr(0, pos);
        tokens.push_back(token);
        stringToSplit.erase(0, pos + delimiter.length());
    }
    tokens.push_back(stringToSplit);
    return tokens;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<Point> points;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::vector<std::string> p = split(line, ",");
        Point newPoint(std::stoi(p[0]), std::stoi(p[1]));
        points.push_back(newPoint);
    }

    long long max = LONG_LONG_MIN;
    for (size_t i = 0; i < points.size() - 1; ++i) {
        Point ip = points[i];
        for (size_t j = i; j < points.size(); ++j) {
            Point jp = points[j];
            long long tArea = ip.getArea(jp);
            if (tArea > max) {
                max = tArea;
            }
        }
    }
    std::cout << "Result: " << max << std::endl;
    return 0;
}
