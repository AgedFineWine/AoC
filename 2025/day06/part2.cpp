#include "aoc.hpp"

size_t combineBuffer(char& op, std::vector<size_t>& buffer) {
    size_t ans = -1;
    if (op == '*') {
        ans = 1;
        for (size_t x : buffer) {
            ans *= x;
            // std::cout << x << " * ";
        }
        // std::cout << "\n";
        return ans;
    } else if (op == '+') {
        ans = 0;
        for (size_t x : buffer) {
            ans += x;
            // std::cout << x << " + ";
        }
        // std::cout << "\n";
        return ans;
    }
    return ans;
}

int main() {
    std::string raw = aoc::readStdinAll();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    std::vector<std::string> lines = aoc::split(raw, "\n");
    size_t rows = lines.size();
    size_t cols = lines[0].size();
    std::vector<size_t> buffer;

    size_t ans = 0;
    size_t currentCol = 0; // the column for 2d grid of input
    char op;
    while (currentCol < cols) {
        std::string num = "";
        bool newProb = true;
        for (size_t row = 0; row < rows; row++) {
            if (currentCol < lines[row].size() && (lines[row][currentCol] == '*' || lines[row][currentCol] == '+')) {
                op = lines[row][currentCol];
            } else if (currentCol < lines[row].size() && lines[row][currentCol] != ' ') {
                num += lines[row][currentCol];
                aoc::trim(num);
                newProb = false;
            }
        }

        if (!newProb) {
            buffer.push_back(std::stoull(num));
        }

        if (newProb || currentCol == cols - 1) {
            size_t sum = combineBuffer(op, buffer);
            buffer.clear();
            ans += sum;
        }

        currentCol++;
    }

    std::cout << ans;

    return 0;
}

