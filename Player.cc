#include "Player.hh"
using namespace std;

Player::Player() {
    vida = 100;
}

Player::Player(int vida, sf::Sprite sprite) {
    this->vida = vida;
    this->sprite = sprite;
    this->sprite.setScale(0.2f, 0.2f);
    this->sprite.setOrigin(50.f, 50.f);
    this->sprite.setPosition(24.f, 135.f);
    //set facing direction
    this->sprite.setRotation(90.f);
    // store sprite.getPosition() in pos
    pos.first = sprite.getPosition().x;
    pos.second = sprite.getPosition().y;
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::take_damage(int hit_points) {
    vida -= hit_points;
}

void Player::position_update() {

    if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) && ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
        {   sprite.move(3.f, -3.f);
            sprite.setRotation(225.f);} //ur
        else if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))) && ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
        {   sprite.move(3.f, 3.f);
            sprite.setRotation(315.f);} //dr
        else if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))) && ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))))
        {   sprite.move(-3.f, -3.f);
            sprite.setRotation(135.f);} //ul gud
        else if (((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))) && ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))))
        {   sprite.move(-3.f, 3.f);
            sprite.setRotation(45.f);} //dl
        
        else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
         {   sprite.move(-3.f, 0.f);
             sprite.setRotation(90.f);} //d
        
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
           { sprite.move(3.f, 0.f);
            sprite.setRotation(270.f);} //l

        else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))   
        {    sprite.move(0.f, -3.f);
            sprite.setRotation(180.f);} //r

        else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {    sprite.move(0.f, 3.f);
            sprite.setRotation(0.f);} //l

        // update pos
        pos.first = sprite.getPosition().x;
        pos.second = sprite.getPosition().y;
        
}

void Player::draw_position(sf::RenderWindow& window) {
    int x = pos.first;
    int y = pos.second;
    sf::Text text;

    sf::Font font;
    font.loadFromFile("assets/Open.ttf");

    text.setFont(font);
    text.setString("x: " + to_string(x) + " y: " + to_string(y));
    text.setCharacterSize(10);
    text.setFillColor(sf::Color::Black);
    text.setPosition(0, 0);

    window.draw(text);
    }