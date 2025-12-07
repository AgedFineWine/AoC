#include "aoc.hpp"

#define BEAM '|'
#define SPLITTER '^'

bool is_valid(const size_t row, const size_t col, const std::vector<std::vector<char>>& grid) {
    return row < grid.size() && col < grid[0].size();
}

int main() {
    std::string raw = aoc::read_stdin_all();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    std::vector<std::string> lines = aoc::split(raw, "\n");
    std::vector<std::vector<char>> grid;
    size_t index_of_s;
    for (std::string& line : lines) {
        grid.push_back(std::vector<char>(line.begin(), line.end()));
        size_t pos = line.find('S');
        if (pos != std::string::npos) index_of_s = pos;
    }
    // shoot the inital beam
    // note: kinda of cheated and basically saw that the input was not a splitter
    // lmao
    grid[1][index_of_s] = '|';
    size_t ans = 0;

    for (size_t iteration = 1; iteration < grid.size(); iteration++) {
        for (size_t col = 0; col < grid[iteration].size(); col++) {
            const char current_cell = grid[iteration][col];
            if (current_cell == BEAM) {
                // check if the cell below is within bounds
                if (is_valid(iteration + 1, col, grid)) {
                    // check if that cell is a splitter
                    // if no spliter continue downwards
                    const char bottom_cell = grid[iteration + 1][col];
                    if (bottom_cell == SPLITTER) {
                        grid[iteration + 1][col - 1] = BEAM;
                        grid[iteration + 1][col + 1] = BEAM;
                        ans += 1;
                    } else {
                        grid[iteration + 1][col] = BEAM;
                    }
                }
            }
        }
    }

    std::cout << ans;

    return 0;
}
