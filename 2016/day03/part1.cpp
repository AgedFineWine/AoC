#include "aoc.hpp"

int main() {
    std::string raw = aoc::read_stdin_all();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    std::vector<std::string> triangles = aoc::split(raw, "\n");

    int numberOfTriangles = 0;
    std::vector<int> legsInt;

    for (std::string legs3 : triangles) {
        std::istringstream iss(legs3);
        std::vector<int> legsInt;
        int v;
        while (iss >> v) legsInt.push_back(v);
        if (legsInt.size() != 3) continue;

        // Constant time of O(3Log3)
        std::sort(legsInt.begin(), legsInt.end());

        if (legsInt[0] + legsInt[1] > legsInt[2]) ++numberOfTriangles;
    }

    std::cout << numberOfTriangles;

    return 0;
}
