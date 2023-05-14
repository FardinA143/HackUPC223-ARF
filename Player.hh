#ifndef PLAYER_HH
#define PLAYER_HH

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

    Player(int vida, const sf::Sprite sprite);

    void draw(sf::RenderWindow& window); // Dibuja el sprite del enemigo en la ventana

    void take_damage(int hit_points);

    void position_update();
    void draw_position(sf::RenderWindow& window);
};

#endif