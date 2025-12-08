#include "aoc.hpp"

bool is_triangle(std::vector<size_t>& legs) {
    sort(legs.begin(), legs.end());
    return legs[0] + legs[1] > legs[2];
}

int main() {
    std::string raw = aoc::read_stdin_all();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    std::vector<std::string> lines = aoc::split(raw, "\n");
    std::vector<std::vector<size_t>> grid;
    for (std::string& x : lines) {
        aoc::trim(x);
        std::vector<std::string> v = aoc::split(x, "  ");
        std::vector<size_t> legs;
        for (std::string& j : v) {
            try{
                legs.push_back(std::stoull(j));
            } catch (...) {
                std::cout << "error:'"<< j<<"'";
            }
        }
        grid.push_back(legs);
    }

    int col = 0;
    size_t ans = 0;
    std::vector<size_t> buffer;
    for (int j = 0; j < 3; j++) {
        col = 0;
        for (size_t i = 0; i < grid.size(); i++) {
            if (buffer.size() != 3)
                buffer.push_back(grid[i][col]);
            if (is_triangle(buffer)) {
                ans++;
                buffer.clear();
            }
        }
    }

    std::cout << ans;

    return 0;
}
