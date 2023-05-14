#ifndef ENEMYPOOL_HH
#define ENEMYPOOL_HH

#include <map>
#include "Enemy.hh"
class EnemyPool {

private:
    map<int, Enemy> pool;   // key = EnemyID, value = Enemy object. no necesitamos eficiencia asi que chill xdd

public:
    EnemyPool();

    void clear_enemies();

    void read();

    void update(float delta);

    void draw_enemy();


};
#endif