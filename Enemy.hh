#ifndef PLAYER_HH
#define PLAYER_HH

#include <SFML/Graphics.hpp>
#include <utility>
#include "Player.hh"
using namespace std;

class Enemy {

private:
    int vida;
    pair<int,int> pos;
    sf::Sprite sprite; // Sprite para representar al enemigo
    sf::Texture texture; // Textura para el sprite
    Player* player; // Puntero al jugador
    bool attacking; // Indica si el enemigo está atacando

public:
    //Constructora 
    Enemy();

    Enemy(int hp, const std::string& texturePath);

    void setPosition(float x, float y);

    sf::Texture& getTexture();

    void take_damage(int hit_points);

    void move(float x, float y);

    void attack(); // Ataca al jugador

    void setPlayer(Player* player); // Establece el puntero al jugador

    void update(float deltaTime); // Actualiza la posición del enemigo

    bool isAttacking(); // Retorna si el enemigo está atacando

    int getVida();

    sf::Sprite getSprite();



};
#endif