#include "aoc.hpp"

void moveLocation(int& x, int& y, const char& c, char grid[5][5]) {
    int copy_y = y;
    int copy_x = x;
    if (c == 'R') {
        copy_y += 1;
        if (copy_y <= 4)
            if (grid[x][copy_y] != '0') y+= 1;
    } else if (c == 'L') {
        copy_y -= 1;
        if (copy_y >= 0)
            if (grid[x][copy_y] != '0') y -= 1;
    } else if (c == 'U') {
        copy_x -= 1;
        if (copy_x >= 0)
            if (grid[copy_x][y] != '0') x -= 1;
    } else if (c == 'D') {
        copy_x += 1;
        if (copy_x <= 4)
            if (grid[copy_x][y] != '0') x += 1;
    }
}

void addCode(char grid[5][5], const int& x, const int& y, std::string& code) {
    char c = grid[x][y];
    code += c;
}

int main() {
    std::string raw = aoc::readStdinAll();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }

    // get each instruction line
    std::vector<std::string> lines = aoc::split(raw, "\n");

    char grid[5][5] = {
        {'0', '0', '1', '0', '0'},
        {'0', '2', '3', '4', '0'},
        {'5', '6', '7', '8', '9'},
        {'0', 'A', 'B', 'C', '0'},
        {'0', '0', 'D', '0', '0'}
    };

    // create pointer for current location
    int x = 2;
    int y = 0;

    // create the answer
    std::string code = "";
    
    for (std::string line : lines) {
        for (char cmd : line) {
            // std::cout << cmd << "\n";
            moveLocation(x, y, cmd, grid);
            // std::cout << "moved to: " << x << " "<< y << "\n";
        }
        addCode(grid, x, y, code);
        // std::cout << "adding code " << code << "\n";
    }

    std::cout << code;
    return 0;
}

