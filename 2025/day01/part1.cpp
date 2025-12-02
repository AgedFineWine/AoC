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
        std::string num = rotation.substr(1);
        if (rotation[0] == 'L') {
            // For left turns
            curr -= stoi(num); 
        } else if (rotation[0] == 'R') {
            // For right turns
            curr += stoi(num);
        }

        if (curr <= -100) curr = -1 * (std::abs(curr) % 100);
        if (curr >= 100) curr = std::abs(curr) % 100;

        if (curr == 0)
            ans++;
    }

    std::cout << ans;
    return 0;
}
