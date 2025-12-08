#include "aoc.hpp"

#define START 'S'
#define EMPTY '.'
#define SPLITTER '^'

size_t num_of_grid_rows = 0;
size_t num_of_grid_col = 0;
std::vector<std::string> grid;

size_t count_timelines(size_t& row, size_t& col, std::unordered_map<std::pair<size_t, size_t>, size_t, aoc::pair_hash>& memo) {
    // validate before accessing a cell in the grid
    // if outside bound it has reached its end
    if (row >= num_of_grid_rows) return 1;
    if (col < 0 || col >= num_of_grid_col) return 1;
    // some constants
    size_t next_row = row + 1;
    size_t left_col = col - 1;
    size_t right_col = col + 1;

    std::pair<size_t, size_t> coordinate = {row, col};
    // has this been calculated yet?
    if (memo.find(coordinate) != memo.end()) {
        return memo[coordinate];
    }

    // calculate since it has not been traversed
    char current_cell = grid[row][col];
    size_t res = 0;
    if (current_cell == EMPTY || current_cell == START) {
        res = count_timelines(next_row, col, memo);
    } else if (current_cell == SPLITTER) {
        size_t left_timeline = count_timelines(next_row, left_col, memo);
        size_t right_timeline = count_timelines(next_row, right_col, memo);
        res = left_timeline + right_timeline;
    }
    memo[coordinate] = res;

    // return 0 since this cell is a beam
    return res;
}

int main() {
    std::string raw = aoc::read_stdin_all();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    grid = aoc::split(raw, "\n");
    num_of_grid_rows = grid.size();
    num_of_grid_col = grid[0].size();
    std::unordered_map<std::pair<size_t, size_t>, size_t, aoc::pair_hash> memo; // to cache the alt timelines given a ( row, col )
    size_t start_row = 0;
    size_t start_col = 0;
    // find the start col index
    for (size_t i = 0; i < grid[0].size(); i++) { 
        if (grid[0][i] == START) {
            start_col = i;
            break;
        }
    }

    size_t ans = count_timelines(start_row, start_col, memo);

    std::cout << ans;

    return 0;
}
