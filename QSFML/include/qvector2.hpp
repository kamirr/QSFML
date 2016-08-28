/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com              *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#ifndef QVECTOR2_HPP
#define QVECTOR2_HPP

#include <SFML/System/Vector2.hpp>
#include <QPoint>
#include <QSize>

namespace qsf
{
    template <typename N>
    class QVector2
        : public sf::Vector2<N>
    {
    public:
        QVector2()
            : sf::Vector2<N>()
        { }
        QVector2(N x, N y)
            : sf::Vector2<N>(x, y)
        { }

        QVector2(sf::Vector2<N> vec)
            : sf::Vector2<N>(vec.x, vec.y)
        { }
        QVector2(QPoint Qp)
            : sf::Vector2<N>(Qp.x(), Qp.y())
        { }
        QVector2(QSize Qp)
            : sf::Vector2<N>(Qp.width(), Qp.height())
        { }

        operator QPoint const() { return QPoint(N(this->x), N(this->y)); }
        operator QSize const()  { return QSize(N(this->x),  N(this->y)); }
    };

	typedef QVector2<int>			QVector2i;
	typedef QVector2<unsigned int>	QVector2u;
	typedef QVector2<float>			QVector2f;

}
#endif // QVECTOR2_HPP

