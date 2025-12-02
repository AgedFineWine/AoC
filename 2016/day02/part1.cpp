#include "aoc.hpp"

void moveLocation(int& x, int& y, const char& c) {
    if (c == 'R') {
        if (y <= 1) y += 1;
    } else if (c == 'L') {
        if (y >= 1) y -= 1;
    } else if (c == 'U') {
        if (x >= 1) x -= 1;
    } else if (c == 'D') {
        if (x <= 1) x += 1;
    }
}

void addCode(int grid[3][3], const int& x, const int& y, std::string& code) {
    int c = grid[x][y];
    code += std::to_string(c);
}

int main() {
    std::string raw = aoc::readStdinAll();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }

    // get each instruction line
    std::vector<std::string> lines = aoc::split(raw, "\n");

    int grid[3][3];
    int c = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid[i][j] = c++;

    // create pointer for current location
    int x = 1;
    int y = 1;

    // create the answer
    std::string code = "";
    
    for (std::string line : lines) {
        for (char cmd : line) {
            // std::cout << cmd << "\n";
            moveLocation(x, y, cmd);
            // std::cout << "moved to: " << x << " "<< y << "\n";
        }
        addCode(grid, x, y, code);
        // std::cout << "adding code " << code << "\n";
    }

    std::cout << code;
    return 0;
}
