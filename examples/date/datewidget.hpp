#ifndef DATEWIDGET_H
#define DATEWIDGET_H

#include <QSFML/qresourcestream.hpp>
#include <QSFML/QSFMLCanvas.hpp>
#include <QSFML/qvector2.hpp>
#include <QSFML/string.hpp>
#include <QDateTime>

class DateWidget
    : public qsf::QSFMLWidget
{
    qsf::QResourceStream fontStream;
    qsf::QVector2i widgetSize;
    sf::Font font;
    sf::Text text;

public:
    DateWidget(QWidget *parent, const QPoint& Position, const QSize& Size);

    void OnInit();
    void OnUpdate();
};

#endif // DATEWIDGET_H
