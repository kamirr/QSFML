/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com              *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#ifndef KEYCONVERTER_HPP
#define KEYCONVERTER_HPP

#include <SFML/Window/Keyboard.hpp>
#include <QKeyEvent>

namespace qsf {
	sf::Keyboard::Key QtKeyToSFML(int QtKey);
}
#endif // KEYCONVERTER_HPP

