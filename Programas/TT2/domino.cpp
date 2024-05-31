#include "Piece.h"
#include "Domino.h"
#include <algorithm>

using namespace std;

bool operator== (Piece a, Piece b) {
    return a.get_left() == b.get_left() && a.get_right() == b.get_right();
}

bool Piece::can_be_right_to(const Piece& other) const {
    return other.get_right() == left_;
}

bool Piece::can_be_left_to(const Piece& other) const {
    return other.get_left() == right_;
}

const Piece& Domino::left() const {
    return *pieces_.begin();
}

const Piece& Domino::right() const {
    return *(--pieces_.end());
}

bool Domino::place_left(const Piece& p) {
    if (find(pieces_.begin(), pieces_.end(),p) == pieces_.end() && p.can_be_left_to(left())) {
        pieces_.push_front(p);
        return true;
    }
    return false;
}

bool Domino::place_right(const Piece& p) {
    if (find(pieces_.begin(), pieces_.end(),p) == pieces_.end() && p.can_be_right_to(right())) {
        pieces_.push_back(p);
        return true;
    }
    return false;
}