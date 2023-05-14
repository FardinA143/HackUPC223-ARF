#include "EnemyPool.hh"

using namespace std;

EnemyPool::EnemyPool() {
    
    rand_pos_V.push_back(make_pair(330, 45)); //V
    rand_pos_H.push_back(make_pair(30, 363)); //H
    rand_pos_V.push_back(make_pair(426, 280)); //V
    rand_pos_H.push_back(make_pair(204, 528)); //H
    rand_pos_V.push_back(make_pair(360, 672)); //V
    rand_pos_H.push_back(make_pair(1032, 381)); //H
    rand_pos_V.push_back(make_pair(1555, 666)); //V
}

void EnemyPool::clear_enemies() {
    pool.clear();
}

void EnemyPool::read(sf::Sprite enemySprite) {
   // vector<Enemy> enemySprites;
 srand(time(nullptr));
    for (int i = 0; i < 3; i++) {
        Enemy enemy;
        enemy = Enemy(enemySprite, 100);
       
        int random = rand() % 2 + 1;
        if (random == 0) {
            random = rand() % rand_pos_V.size();
            if (rand_pos_V.size() == 0) {
                random = rand() % rand_pos_H.size();
                enemy.setPosition(rand_pos_H[i].first, rand_pos_H[i].second);
                rand_pos_H.erase(rand_pos_H.begin() + i);
            }
            else {enemy.setPosition(rand_pos_V[i].first, rand_pos_V[i].second);
            rand_pos_V.erase(rand_pos_V.begin() + i);}
        }
        else {
            random = rand() % rand_pos_H.size();
            if (rand_pos_H.size() == 0) {
                random = rand() % rand_pos_V.size();
                enemy.setPosition(rand_pos_V[i].first, rand_pos_V[i].second);
                rand_pos_V.erase(rand_pos_V.begin() + i);
            }
            else {
                enemy.setPosition(rand_pos_H[i].first, rand_pos_H[i].second);
                rand_pos_H.erase(rand_pos_H.begin() + i);
            }

        }
        
        pool.push_back(enemy);
    }
}

// void EnemyPool::update(float delta) {
//     for (auto& enemy : pool) {
//             enemy.update(delta);
//     } 
// }

void EnemyPool::draw_enemy(sf::RenderWindow& window) {
    for (auto& enemy : pool) enemy.draw(window);
}
