/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com	       *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#ifndef STRING_H
#define STRING_H

#include <QString>
#include <SFML/System/String.hpp>

namespace qsf
{
    class String
        : public QString
    {
        using QString::QString;
    public:
        String(sf::String str);
        operator sf::String const();
    };
}
#endif // STRING_H
