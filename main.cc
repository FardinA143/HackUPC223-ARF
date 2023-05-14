#include <SFML/Graphics.hpp>
#include "Enemy.hh"
#include "EnemyPool.hh"


int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "HackRooms");
   
    string texturePath = "assets/player.png"; // Cambiar por la ruta correcta
    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("enemy.png"); //cambiar .png al bueno

    sf::Texture texture;                                //jugador
    texture.loadFromFile("assets/player.png");
    sf::Sprite shape(texture);

    sf::Texture backgroundTexture;                         //fondo
    backgroundTexture.loadFromFile("ruta/al/fondo.png");
    sf::Sprite backgroundSprite(backgroundTexture);

    shape.setPosition(100.f, 100.f);
    EnemyPool enemies;
    enemies.read();

    sf::Clock clock;
    float delta = 0.f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // Actualizar la posición del objeto
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
            shape.move(-1.f, 0.f);
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
            shape.move(1.f, 0.f);

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))   
            shape.move(0.f, -1.f);

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            shape.move(0.f, 1.f);
        
        delta = clock.restart().asSeconds();    //Time update 
        enemies.update(delta);             
        // Borrar la ventana
        window.clear(sf::Color::White);

        window.draw(backgroundSprite);

        // Dibujar el objeto
        window.draw(shape);

        enemies.draw_enemy();
        
        // Actualizar la ventana
        window.display();
    }

    return 0;
}
