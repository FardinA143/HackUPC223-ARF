#ifndef ENEMYPOOL_HH
#define ENEMYPOOL_HH

#include <map>
#include "Enemy.hh"
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>
class EnemyPool {

private:
    vector<Enemy> pool;   // key = EnemyID, value = Enemy object. no necesitamos eficiencia asi que chill xdd
    vector<pair<int, int>> rand_pos_V, rand_pos_H; //posiciones aleatorias
public:
    EnemyPool();

    void clear_enemies();

    void read(sf::Sprite enemySprite);

    //void update(double delta);

    void draw_enemy(sf::RenderWindow& window);


};
#endif