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

        operator QPoint const() { return QPoint(N(this->x), N(this->y)); }
        operator QSize const()  { return QSize(N(this->x),  N(this->y)); }
    };

    typedef QVector2<int> QVector2i;
    typedef QVector2<unsigned int> QVector2u;
    typedef QVector2<float> QVector2f;

}
#endif // QVECTOR2_HPP

