#include "EnemyPool.hh"

using namespace std;

EnemyPool::EnemyPool() {

}

void EnemyPool::clear_enemies() {
    for (auto it = pool.begin(); it != pool.end(); ++it) {
        if (it->second.getVida() <= 0) {    //oye la llave pongo int
            pool.erase(it);
            break; // Importante salir del bucle si eliminamos un elemento
        }
    } 
}  

void EnemyPool::read() {
    vector<sf::Sprite> enemySprites;
    sf::Sprite enemySprite;
    for (int i = 0; i < 5; i++) {
        Enemy enemy(100, "assets/enemy.png");
        enemy.setPosition(100.f + i * 100.f, 300.f);
        pool.insert(make_pair(i, enemy));
    
        enemySprite.setTexture(enemy.getTexture());
        enemySprites.push_back(enemySprite);
    }
}

void EnemyPool::update(float delta) {
    for (auto& enemy : pool) {
            enemy.update(delta);
    } 
}

void EnemyPool::draw_enemy() {
    for (const auto& enemy : pool) window.draw(enemy.getSprite());
}
