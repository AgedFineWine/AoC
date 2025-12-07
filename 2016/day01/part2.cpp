#include "aoc.hpp"

enum Direction {
    NORTH,
    SOUTH,
    WEST,
    EAST,
};

enum Move {
    LEFT,
    RIGHT
};

class Coordinate {
public:
    int x;
    int y;

    Coordinate(int ix, int iy) : x(ix), y(iy) {}

    bool operator==(const Coordinate& other) const {
        return other.x == x && other.y == y;
    }

    struct Hash {
        std::size_t operator()(const Coordinate& c) const noexcept {
            // Combine the hash of x and y using bitwise operations for uniqueness
            return (std::hash<int>()(c.x) ^ (std::hash<int>()(c.y) << 1));
        }
    };
};

void findNewDirection(Direction& d, Move m) {
    switch (d) {
        case Direction::NORTH:
            (m == Move::LEFT) ? d = Direction::WEST : d = Direction::EAST;
            break;
        case Direction::SOUTH:
            (m == Move::LEFT) ? d = Direction::EAST : d = Direction::WEST;
            break;
        case Direction::EAST:
            (m == Move::LEFT) ? d = Direction::NORTH : d = Direction::SOUTH;
            break;
        case Direction::WEST:
            (m == Move::LEFT) ? d = Direction::SOUTH : d = Direction::NORTH;
    }
}

Move convertToMoveEnum(char s) {
    if (s == 'L') return Move::LEFT;
    return Move::RIGHT;
}

bool findNewCoordinate(Coordinate& old, int dist, Direction facing, std::unordered_set<Coordinate, Coordinate::Hash>& visited) {
    for (int i = 0; i < dist; i++) {
        switch (facing) {
            case NORTH:
                old.y += 1;
                break;
            case SOUTH:
                old.y -= 1;
                break;
            case EAST:
                old.x += 1;
                break;
            case WEST:
                old.x -= 1;
                break;
        }
        Coordinate next = old;
        if (visited.find(next) != visited.end()) {
            std::cout << std::abs(next.x) + std::abs(next.y);
            return true;
        }
        visited.insert(next);
    }
    return false;
}

int main() {
    // Read full input from stdin (paste the puzzle input and EOF/ctrl-D).
    std::string raw = aoc::read_stdin_all();
    aoc::trim(raw);
    if (raw.empty()) {
        std::cerr << "Warning: no input on stdin.\n";
    }
    auto lines = aoc::split(raw, ", ");

    // enum for North, East, South, West
    // initial pointer pointing North
    Direction facing = NORTH;
    Coordinate coord(0, 0);
    std::unordered_set<Coordinate, Coordinate::Hash> visited;

    // for each direction consider L and R possiblities
    for (std::string dir : lines) {
        std::string dist(dir.begin() + 1, dir.end());
        // find new facing direction
        findNewDirection(facing, convertToMoveEnum(dir[0]));
        // then calculate the (x,y) at final destination
        bool b =findNewCoordinate(coord, stoi(dist), facing, visited);
        if (b) break;
    }

    // answer should be the abs(x) + abs(y) given the (x,y) coordinate
    // answer should be in O(n)

    return 0;
}

