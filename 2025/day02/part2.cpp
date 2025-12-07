#include "aoc.hpp"

std::vector<long long> splitByLength(long long& num, long long& length) {
    std::string s = std::to_string(num);
    std::vector<long long> result;
    size_t r;

    for (size_t i = 0; i < s.size(); i += length) {
        std::stringstream sstream(s.substr(i, length));
        sstream >> r;
        result.push_back(r);
    }
    // for ( auto x : result) std::cout << x << ", ";
    // std::cout << std::endl;
    return result;
}

bool all(std::vector<long long> subs) {
    for (int i = 1; i < subs.size(); i++) {
        if (subs[i-1] != subs[i]) {
            return false;
        }
    }
    return true;
}

bool check(long long& number, long long& sizeOfNumber) {
    for (long long length = 1; length <= sizeOfNumber / 2; length++) {
        if (sizeOfNumber % length == 0) {
            std::vector<long long> subs = splitByLength(number, length);
            if (all(subs)) return true;
        }
    }
    return false;
}

int main() {
    std::string raw = aoc::read_stdin_all();
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

        for (long long number = lower; number <= upper; number++) {
            std::string number_str = std::to_string(number);
            long long number_str_len = number_str.size();

            // check if a part of the number repeats as least once
            if (check(number, number_str_len)) repeating.push_back(number);
        }
    }

    long long ans = 0;
    for (long long num : repeating) ans += num;

    std::cout << ans;

    return 0;
}

