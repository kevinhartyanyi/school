#ifndef CORD_H
#define CORD_H


enum Players {Red, Blue, Neutral, Damaged};
enum Directions {Left, Right, Up, Down};
enum Attacks {Laser, Punch};

struct Cord
{
    int x;
    int y;
    friend bool operator!=( const Cord& c1, const Cord& c2);
};

inline bool operator!=( const Cord& c1, const Cord& c2)
{
    return (c1.x != c2.x || c1.y != c2.y);
}

#endif // CORD_H
