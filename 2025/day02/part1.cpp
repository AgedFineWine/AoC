#include "aoc.hpp"

int main() {
    std::string raw = aoc::readStdinAll();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    std::vector<std::string> intervals = aoc::split(raw, ",");
    std::vector<long long> repeating;

    for (std::string interval : intervals) {
        std::vector<std::string> bounds = aoc::split(interval, "-");
        long long lower = stoll(bounds[0]);
        long long upper = stoll(bounds[1]);

        for (long long i = lower; i <= upper; i++) {
            std::string i_str = std::to_string(i);
            long long i_str_len = i_str.size();
            if (i_str_len % 2 == 0) {
                if (i_str.substr(0, i_str_len / 2) == i_str.substr(i_str_len / 2)) {
                    repeating.push_back(i);
                }
            }
        }
    }

    long long ans = 0;
    for (long long num : repeating) ans += num;

    std::cout << ans;

    return 0;
}
