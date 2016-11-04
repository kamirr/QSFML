#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <SFML/Graphics.hpp>
#include <QSFML/qresourcestream.hpp>
#include <QSFML/QSFMLCanvas.hpp>
#include <QSFML/qvector2.hpp>
#include <QSFML/string.hpp>
#include <QMainWindow>

class TestWidget
: public qsf::QSFMLWidget
{
	Q_OBJECT

public:
	TestWidget(QMainWindow* Parent, const QPoint& Position, const QSize& Size);
	~TestWidget();

	void OnInit();
	void OnUpdate();

private:
	qsf::QResourceStream fontStream;

	size_t fontSize;

	sf::Font bitFont;
	sf::Text bitText;

	float TextColorR;
	float TextColorG;

	int colorModR;
	int colorModG;

	int counter;
};

#endif // TESTWIDGET_H
