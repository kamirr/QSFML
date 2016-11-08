/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com              *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */
//! @file QString declaration and partial implementation

#ifndef STRING_H
#define STRING_H

#include <SFML/System/String.hpp>
#include <iostream>
#include <QString>

namespace qsf {
	//! \class String
	//! \brief (almost) QString castable to sf::String
	//!
	//! Use this class to operate on QString and use it in sf::Text::setString() etc.
	class String
	: public QString {
	public:
		//! \brief Quite universal constructor
		//!
		//! \param [in] obj – object/variable
		//!
		//! Can take as parameter any variable or object, that can be given to QString constructor.\n
		//! Calls QString(ojb).
		template<typename T>
		String(T obj)
		: QString(obj)
		{ }

		//! \brief std::string constructor
		//!
		//! \param [in] obj – std::string instance
		//!
		//! Allows initializing String using std::string object.
		String(std::string obj)
		: QString(obj.c_str())
		{ }

		//! \brief sf::String constructor
		//!
		//! \param [in] obj – sf::String instance
		//!
		//! Allows initializing String using sf::String object.
		String(sf::String str);

		//! \brief QString::number() method overload
		//!
		//! \param [in] num – Number
		//!
		//! Does exact same thing as QString::number(), but returns qsf::String instead of QString.
		template<typename T>
		static String number(T num) {
			return String(QString::number(num));
		}

		//! \brief QString::arg() method overload, takes any supported type.
		//!
		//! \param [in] var – Argument
		//!
		//! Overload QString::arg() method from QString, so it could return qsf::String
		template<typename T>
		String arg(T var) const {
			return String(static_cast<const QString*>(this)->arg(var));
		}

		//! \brief QString::arg() method overload, takes sf::String as parameter
		//!
		//! \param [in] var – Argument
		//!
		//! Overload QString::arg() method from QString taking sf::String as parameter.
		String arg(sf::String str) const;

		//! \brief QString::arg() method overload, takes qsf::String as parameter.
		//!
		//! \param [in] var – Argument
		//!
		//! Overload QString::arg() method from QString taking qsf::String as parameter.
		String arg(String str) const;

		//! \brief Operator allowing casting to sf::String
		//!
		//! \code
		//! qsf::String str = QDateTime::currentDateTime().toString();
		//! someSfmlText.setString(str); //OK
		//! \endcode
		operator sf::String const();

		//! \brief std::ostream << operator support
		//!
		//! Allows printing qsf::String to std::ostream like that:
		//! \code
		//! qsf::String str = QDateTime::currentDateTime().toString();
		//! std::cout << str << std::endl;
		//! \endcode
		friend std::ostream& operator <<(std::ostream& out, const String& string) {
			return out << string.toStdString();
		}
	};
}
#endif // STRING_H
