#ifndef KEYCONVERTER_HPP
#define KEYCONVERTER_HPP

#include <SFML/Window/Keyboard.hpp>
#include <QKeyEvent>

sf::Keyboard::Key QtKeyToSFML(int QtKey);

#endif // KEYCONVERTER_HPP
