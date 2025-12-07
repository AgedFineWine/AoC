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

void findNewCoordinate(std::unique_ptr<Coordinate>& old, int dist, Direction facing) {
    switch (facing) {
        case NORTH:
            old->y += dist;
            break;
        case SOUTH:
            old->y -= dist;
            break;
        case EAST:
            old->x += dist;
            break;
        case WEST:
            old->x -= dist;
            break;
    }
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
    std::unique_ptr<Coordinate> coord(new Coordinate(0, 0));

    // for each direction consider L and R possiblities
    for (std::string dir : lines) {
        std::string dist(dir.begin() + 1, dir.end());
        // find new facing direction
        findNewDirection(facing, convertToMoveEnum(dir[0]));
        // then calculate the (x,y) at final destination
        findNewCoordinate(coord, stoi(dist), facing);
    }

    // answer should be the abs(x) + abs(y) given the (x,y) coordinate
    // answer should be in O(n)
    std::cout << abs(coord->x) + abs(coord->y);

    return 0;
}
