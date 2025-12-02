#include "aoc.hpp"

int main() {
    std::string raw = aoc::readStdinAll();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    std::vector<std::string> lines = aoc::split(raw, "\n");

    // starting number
    int curr = 50;

    // number of times it touched 0
    int ans = 0;

    for (std::string rotation : lines) {
        if (rotation.empty()) continue;

        char dirChar = rotation[0];
        long long num = std::stoll(rotation.substr(1)); // absolute number of clicks
        int d = (dirChar == 'L') ? -1 : 1;
        long long s = std::llabs(num);

        // compute smallest positive k0 in [1..100] such that (curr + d*k0) % 100 == 0
        // k0 is the number required to rotate to get to 0
        int p = curr; // 0..99
        int k0;
        if (d == 1) {
            k0 = (100 - p) % 100;
        } else {
            k0 = p % 100;
        }
        if (k0 == 0) k0 = 100;

        long long hits = 0;
        if (s >= k0) hits = 1 + (s - k0) / 100; // count the number of loops it hits so we divide by 100
        ans += hits;

        // update curr (final position) properly (handle negative modulo)
        int rel = ( curr + d * (std::abs(num) % 100) );
        int endPos = rel < 0 ? 100 + rel : rel % 100;
        curr = endPos;
    }

    std::cout << ans;
    return 0;
}
