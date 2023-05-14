#include "Enemy.hh"
using namespace std;

Enemy::Enemy()
{
    vida = 100;
    attacking = false;
}

Enemy::Enemy(sf::Sprite sprite, int hp)
{
    vida = hp;
    this->sprite = sprite;
    attacking = false;
    this->sprite.setOrigin(50, 50);
    this->sprite.setScale(0.2f, 0.2f);

}

void Enemy::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Texture &Enemy::getTexture() {
    return texture;
}

void Enemy::take_damage(int hit_points) {
    vida -= hit_points;
    if (vida <= 0)
        sprite.setPosition(sf::Vector2f(-1000.0f, -1000.0f)); // sep
}

// void Enemy::move(double seconds) {
//     if (is_VERT) {
//         if (sprite.getRotation() == 90) {
//             sprite.setRotation(0);

//         }
//         else {
//             sprite.setRotation(270);
           
            
//         }
//     }
        
    
//     else {
//         if (sprite.getRotation() == 90) {
//             if(seconds == 0.0) sprite.setRotation(180);
//             pos.first -= 1;
//             sprite.setPosition(pos.first, pos.second);
//         }
//         else {
//             if(seconds == 0.0) sprite.setRotation(90);
//             pos.first += 1;
//             sprite.setPosition(pos.first, pos.second);
            
//         }
//     }
// }

void Enemy::attack() {
    player.take_damage(10);    
}



int Enemy::getVida() {
    return vida;
}

void Enemy::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}
