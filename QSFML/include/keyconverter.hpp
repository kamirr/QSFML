/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com              *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */
 //! @file
 //! File containg key converting-related functions declarations.

#ifndef KEYCONVERTER_HPP
#define KEYCONVERTER_HPP

#include <SFML/Window/Keyboard.hpp>
#include <QKeyEvent>

namespace qsf {
	//! \brief Function converting Qt key code to SFML's one.
	//!
	//! \param [in]	QtKey	Qt Key code
	//!
	//! \return SFML key code
	sf::Keyboard::Key QtKeyToSFML(int QtKey);
}
#endif // KEYCONVERTER_HPP

