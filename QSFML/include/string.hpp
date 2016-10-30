/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com              *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#ifndef STRING_H
#define STRING_H

#include <SFML/System/String.hpp>
#include <iostream>
#include <QString>
namespace qsf {
	class String
	: public QString {
	public:
		/* Quite universal constructor */
		template<typename T>
		String(T obj)
		: QString(obj)
		{ }

		/* Constructor taking std::string */
		String(std::string obj)
		: QString(obj.c_str())
		{ }

		/* Constructor taking SFML string */
		String(sf::String str);

		/* Overload 'number' method from QString,
		 * so it could return qsf::String*/
		template<typename T>
		static String number(T num) {
			return String(QString::number(num));
		}

		/* Overload 'arg' method from QString,
		 * so it could return qsf::String + adds
		 * overloads for qsf::String and sf::String*/
		template<typename T>
		String arg(T var) const {
			return String(static_cast<const QString*>(this)->arg(var));
		}
		String arg(sf::String str) const;
		String arg(String str) const;

		/* Enable casting to sf::String */
		operator sf::String const();

		/* Implement std::cout (std::ofstream etc. too) support */
		friend std::ostream& operator <<(std::ostream& out, const String& string) {
			return out << string.toStdString();
		}
	};
}
#endif // STRING_H
