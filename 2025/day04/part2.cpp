#include "aoc.hpp"

bool isValid(int check_row, int check_col, int row, int col) {
    if (check_row > row - 1) return false;
    if (check_row < 0) return false;
    if (check_col > col - 1) return false;
    if (check_col < 0) return false;
    return true;
}

bool isPaper(int row, int col, std::vector<std::vector<std::string>>& grid) {
    if (grid[row][col] == "@") return true;
    return false;
}

void canAccess(int check_row, int check_col, int& ans, std::vector<std::vector<std::string>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int count = 0;
    if (grid[check_row][check_col] != "@") return;

    if (isValid(check_row - 1, check_col, rows, cols) && isPaper(check_row - 1, check_col, grid)) count++;
    if (isValid(check_row - 1, check_col + 1, rows, cols) && isPaper(check_row - 1, check_col + 1, grid)) count++;
    if (isValid(check_row - 1, check_col - 1, rows, cols) && isPaper(check_row - 1, check_col - 1, grid)) count++;

    if (isValid(check_row, check_col - 1, rows, cols) && isPaper(check_row, check_col - 1, grid)) count++;
    if (isValid(check_row, check_col + 1, rows, cols) && isPaper(check_row, check_col + 1, grid)) count++;

    if (isValid(check_row + 1, check_col, rows, cols) && isPaper(check_row + 1, check_col, grid)) count++;
    if (isValid(check_row + 1, check_col - 1, rows, cols) && isPaper(check_row + 1, check_col - 1, grid)) count++;
    if (isValid(check_row + 1, check_col + 1, rows, cols) && isPaper(check_row + 1, check_col + 1, grid)) count++;


    if (count < 4) {
        ans++;
        grid[check_row][check_col] = "x";
    }
}

int main() {
    std::string raw = aoc::readStdinAll();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    std::vector<std::string> lines = aoc::split(raw, "\n");

    // build out a 2d representation of the input
    std::vector<std::vector<std::string>> grid;
    int lineNumber = 0;
    for (std::string line : lines) {
        grid.push_back(std::vector<std::string>());
        for (char c : line) {
            std::string cs = "";
            cs += c;
            grid[lineNumber].push_back(cs);
        }
        lineNumber++;
    }

    // for (auto x : grid)
    //     for (auto j : x)
    //         std::cout << j << " "; 
    //     std::cout << "\n";

    int total = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    while (true) {
        int ans = 0;
        for (int line = 0; line < rows; line++) {
            for (int paper = 0; paper < cols; paper++) {
                canAccess(line, paper, ans, grid);
            }
        }

        if (ans == 0) break;
        else total += ans;
    }

    std::cout << total;

    return 0;
}

