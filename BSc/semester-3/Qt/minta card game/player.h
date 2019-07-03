#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

// j�t�kos t�pusa
class Player
{
public:
   Player(QString n) : _name(n), _hits(0), _misses(0), _victories(0) {}
   void newGame() { _hits = _misses = 0; } // �j j�t�k
   void addHit() { _hits++; } // �j tal�lat
   void addMiss() { _misses++; } // �j mell�l�v�s
   void addVictory() { _victories++; } // �j gy�zelem

   QString getName() const { return _name; }
   int getHits() const { return _hits; }
   int getMisses() const { return _misses; }
   int getVictories() const { return _victories; }

private:
   QString _name;
   int _hits;
   int _misses;
   int _victories;
};

#endif // PLAYER_H
