#ifndef ENEMY_HH
#define ENEMY_HH

#include <SFML/Graphics.hpp>
#include <utility>
using namespace std;

class Player {

private:
    int vida;
    pair<int,int> pos;
    sf::Sprite sprite; // Sprite para representar al enemigo
    sf::Texture texture; // Textura para el sprite

public:
    //Constructora 
    Player();

    Player(int vida, int proximidad, const std::string& texturePath);

    void draw(sf::RenderWindow& window); // Dibuja el sprite del enemigo en la ventana

    void take_damage(int hit_points);

};

#endif