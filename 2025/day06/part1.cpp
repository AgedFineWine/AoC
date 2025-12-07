#include "aoc.hpp"

void combineBuffer(std::string& op, std::vector<std::vector<std::string>>& buffer, size_t& ans, size_t& rows, size_t& bufferCol) {
    if (op == "*") {
        size_t x = 1;
        for (size_t i = 0; i < rows - 1; i++) {
            x *= std::stoull(buffer[i][bufferCol]);
        }
        // std::cout << "adding" << x << std::endl;
        ans += x;
    } else if (op == "+") {
        size_t x = 0;
        for (size_t i = 0; i < rows - 1; i++) {
            x += std::stoull(buffer[i][bufferCol]);
        }
        // std::cout << "adding" << x << std::endl;
        ans += x;
    }
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
    // initialize the 2d matrix, buffer(5, 3) = { 3, 3, 3, 3, 3 }
    // init more than we need
    std::vector<std::vector<std::string>> buffer(rows, std::vector<std::string>(cols, ""));

    size_t ans = 0;
    size_t currentCol = 0; // the column for 2d grid of input
    size_t bufferCol = 0;
    while (currentCol <= cols - 1) { // for each line
        bool newProb = true;
        for (size_t row = 0; row < rows; row++) {
            if (currentCol < lines[row].size() && lines[row][currentCol] != ' ') {
                buffer[row][bufferCol] += lines[row][currentCol];
                aoc::trim(buffer[row][bufferCol]);
                // std::cout << "'"<< buffer[row][bufferCol]<< "'\n";
                newProb = false;
            }
        }

        // std::cout << currentCol << "==?" << cols - 1<< "\n";
        if (newProb || currentCol == cols - 1) {
            // for (int i = 0; i < rows ; i++) std::cout << buffer[i][bufferCol] << " ";
            // std::cout << "\n";
            std::string op = buffer[buffer.size() - 1][bufferCol]; // operation on last row
            combineBuffer(op, buffer, ans, rows, bufferCol);
            bufferCol++;
        }

        currentCol++;
    }

    std::cout << ans;

    return 0;
}
