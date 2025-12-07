#include "aoc.hpp"

std::vector<size_t> findLargest(std::vector<size_t>& bank, size_t& firstIndex, size_t remainingBattery) {
    size_t largest = bank[firstIndex + 1];
    size_t largestIndex = firstIndex + 1;
    for (size_t battery = firstIndex + 1; battery < bank.size() - remainingBattery; battery++) {
        if (bank[battery] > largest) {
            largest = bank[battery];
            largestIndex = battery;
        }
    }
    return {largest, largestIndex};
}

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
        size_t batteriesLeft = 12; // How many batteries do we need to find in the bank?
        std::string jolt = "";
        for (size_t battery = 0; battery < bank.size() - (batteriesLeft - 1); battery++) { // 11 more batteries to find
            if (bank[battery] > firstLargest) {
                firstLargest = bank[battery];
                firstIndex = battery;
            }
        }
        batteriesLeft--;
        jolt += std::to_string(firstLargest);

        for (size_t battery = 0; battery < 11; battery++) {
            std::vector<size_t> l = findLargest(bank, firstIndex, batteriesLeft - 1);
            jolt += std::to_string(l[0]);
            firstIndex = l[1];
            batteriesLeft--;
        }

        size_t ax;
        std::stringstream z(jolt);
        z >> ax;
        allJolt.push_back(ax);
    }

    size_t sum = 0;
    for (auto x : allJolt) sum += x;
    std::cout << sum;

    return 0;
}
