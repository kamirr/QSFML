#ifndef DATEWIDGET_H
#define DATEWIDGET_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <QSFML/qresourcestream.hpp>
#include <QSFML/QSFMLCanvas.hpp>
#include <QSFML/qvector2.hpp>
#include <QSFML/string.hpp>
#include <QDateTime>
#include <iostream>

class DateWidget
    : public qsf::QSFMLWidget
{
	/* Stream loading data from QResource */
	qsf::QResourceStream fontStream;

	/* Needed to locate text */
	qsf::QVector2i widgetSize;

	/* Text & font */
	sf::Font font;
	sf::Text text;

public:
	DateWidget(QWidget *parent, const QPoint& Position, const QSize& Size);
	virtual ~DateWidget() {
		/* Half-explicit call is required to use OnDestroy method */
		OnDestroy();
	}

	/* Called on init */
	virtual void OnInit();

	/* Called on update */
	virtual void OnUpdate();

	/* Called when widget is being destroyed */
	virtual void OnDestroy();
};

#endif // DATEWIDGET_H
