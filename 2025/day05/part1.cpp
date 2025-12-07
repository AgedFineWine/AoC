#include "aoc.hpp"

bool isFresh(std::vector<std::vector<size_t>>& mergedIntervals, size_t& item) {
    for (std::vector<size_t> interval : mergedIntervals) {
        if (interval[0] <= item && item <= interval[1]) return true;
    }
    return false;
}

int main() {
    std::string raw = aoc::read_stdin_all();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    // extract and organize the relevant data from the input
    std::vector<std::string> lines = aoc::split(raw, "\n");
    std::vector<std::vector<size_t>> intervals;
    std::vector<std::vector<size_t>> mergedIntervals;
    std::vector<size_t> items;
    size_t pl;
    for (std::string line : lines) {
        if (line.find('-') != std::string::npos)  {
            std::vector<std::string> interval = aoc::split(line, "-");
            size_t start = std::stoull(interval[0]);
            size_t end = std::stoull(interval[1]);
            intervals.push_back({start, end});

        } else if (line != "") { // ignore the space separating interval and items
            std::stringstream ss(line);
            ss >> pl;
            items.push_back(pl);
        }
    }

    // sort in ascending
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<size_t>& a, const std::vector<size_t>& b) {
        return a[0] < b[0]; // if true vec a comes before vec b
    });

    mergedIntervals.push_back({intervals[0][0], intervals[0][1]});
    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] < mergedIntervals[mergedIntervals.size() - 1][1]) {
            if (mergedIntervals[mergedIntervals.size() - 1][1] < intervals[i][1]) // check if new bound is higher than old
                mergedIntervals[mergedIntervals.size() - 1][1] = intervals[i][1]; // increasing the previous interval's upperbound
        }
        else {
            mergedIntervals.push_back(intervals[i]);
        }
    }

    size_t ans = 0;
    for (size_t item : items) {
        // std::cout << item << " ";
        if (isFresh(mergedIntervals, item)) ans++;
    }
    std::cout << ans;

    return 0;
}
