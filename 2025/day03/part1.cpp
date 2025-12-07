#include "aoc.hpp"

int main() {
    std::string raw = aoc::read_stdin_all();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    std::vector<std::string> lines = aoc::split(raw, "\n");
    std::vector<std::vector<size_t>> lines_int;
    std::vector<size_t> allJolt;

    size_t c = 0;
    for (std::string line : lines) {
        lines_int.push_back(std::vector<size_t>());
        for (char j: line) {
            size_t num = j - '0';
            lines_int[c].push_back(num);
        }
        c++;
    }

    for (std::vector<size_t> bank : lines_int) {
        size_t firstLargest = bank[0];
        size_t firstIndex = 0;
        for (size_t battery = 0; battery < bank.size() - 1; battery++) {
            if (bank[battery] > firstLargest) {
                firstLargest = bank[battery];
                firstIndex = battery;
            }
        }

        size_t secondLargest = bank[firstIndex + 1];
        for (size_t battery = firstIndex + 1; battery < bank.size(); battery++) {
            if (bank[battery] > secondLargest) {
                secondLargest = bank[battery];
            }
        }

        size_t ax;
        std::string jolt = std::to_string(firstLargest) + std::to_string(secondLargest);
        // std::cout << jolt << "\n";
        std::stringstream z(jolt);
        z >> ax;
        allJolt.push_back(ax);
    }

    size_t sum = 0;
    for (auto x : allJolt) sum += x;
    std::cout << sum;

    return 0;
}