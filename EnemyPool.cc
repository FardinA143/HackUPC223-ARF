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

int EnemyPool::get_nearest_enemy(pair <int, int> pos) {
    int nearest_enemy;
    double min = 50;
    int best = -1;
    for (int i = 0; i < pool.size(); i++) {
        double distance = sqrt(pow(pool[i].getPos().first - pos.first, 2) + pow(pool[i].getPos().second - pos.second, 2));
        if (distance < min ) {
            min = distance;
            nearest_enemy = i;
        }
    }
    return nearest_enemy;
    }

    void EnemyPool::delete_enemy(int i) {
        pool.erase(pool.begin() + i);
    }

    int EnemyPool::take_damage(int hit_points, int id) {
        pool[id].take_damage(hit_points);
        return pool[id].getVida();
    }