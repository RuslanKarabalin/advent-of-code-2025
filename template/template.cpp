#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    size_t n;
    std::cin >> n;

    std::vector<int> vector;

    for (size_t i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        vector.push_back(v);
    }

    return 0;
}
