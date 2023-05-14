#include <SFML/Graphics.hpp>
#include "Player.hh"
#include "Enemy.hh"
#include "EnemyPool.hh"


int main() {
    sf::RenderWindow window(sf::VideoMode(1366, 768), "HackRooms");

    // sf::Texture backgroundTexture;                         //fondo
    // backgroundTexture.loadFromFile("assets/background.jfif");
    // sf::Sprite backgroundSprite(backgroundTexture);
    // backgroundSprite.setPosition(50.f, 50.f); 
    // window.setFramerateLimit(250);
    sf::Image backgroundImage;
backgroundImage.loadFromFile("assets/background.png");

sf::Texture backgroundTexture;
backgroundTexture.loadFromImage(backgroundImage);

sf::RectangleShape backgroundShape(sf::Vector2f(window.getSize().x, window.getSize().y));
backgroundShape.setTexture(&backgroundTexture);


    // string texturePath = "assets/player.png"; // Cambiar por la ruta correcta
   // sf::Texture enemyTexture;
   // enemyTexture.loadFromFile("assets/enemy.png"); //cambiar .png al bueno

    sf::Texture texture;                                //jugador
    texture.loadFromFile("assets/player.png");
    sf::Sprite userSprite(texture);

    Player userPlayer;

    userPlayer = Player(100, userSprite);

    EnemyPool enemies;
    sf::Texture enemyTexture;
    enemyTexture.loadFromFile("assets/enemy.png");
    sf::Sprite enemySprite(enemyTexture);
    enemies.read(enemySprite);

    //sf::Clock clock;
   // double delta = 0.0;
   // int seconds = 0;
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        // Actualizar la posición del objeto
        userPlayer.position_update();
        
       // delta = static_cast<double>( clock.restart().asSeconds());   //Time update 

        //if (delta >= 3.0) delta = 0.0; //Si el tiempo es mayor a 3 segundos, se reinicia el reloj
       //enemies.update(delta);             
        // Borrar la ventana
        window.clear(sf::Color::Black);

        window.draw(backgroundShape);

        // Dibujar el objeto
        userPlayer.draw(window);
        userPlayer.draw_position(window);
        enemies.draw_enemy(window);
        
        // Actualizar la ventana
        window.display();
    }

    return 0;
}
