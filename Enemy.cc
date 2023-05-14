#include "Enemy.hh"
using namespace std;

Enemy::Enemy()
{
    vida = 100;
    attacking = false;
}

Enemy::Enemy(int hp, const std::string &texturePath)
{
    vida = hp;
    texture.loadFromFile(texturePath);
    sprite.setTexture(texture);
    attacking = false;
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

void Enemy::move(float x, float y) {
    pos.first += x;
    pos.second += y;
    sprite.setPosition(pos.first, pos.second);
}

void Enemy::attack() {
    player->take_damage(10);    //a mi no me va, solo va con raton? con teclado comote paso video
} // oye una cosa. El vscode si haces clic derecho sobre una funcion, y le das a peek > peek definition, te abre la seccion del hh correspondiente a la funcion sin que cambies de archivos. tech tip god

void Enemy::update(float deltaTime) {
    if (!attacking) {
        pos.first += 10 * deltaTime;               // Mover en la dirección x a la velocidad indicada
        sprite.setPosition(pos.first, pos.second); // Actualizar la posición del sprite
    }
}

int Enemy::getVida() {
    return vida;
}

sf::Sprite Enemy::getSprite() {
    return sprite;
}
