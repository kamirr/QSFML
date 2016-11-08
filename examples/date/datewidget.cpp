#include "datewidget.hpp"

DateWidget::DateWidget(QWidget *parent, const QPoint &Position, const QSize &Size)
	: qsf::QSFMLWidget(parent, Position, Size, 50),
	  widgetSize(Size)
{ }

void DateWidget::OnInit() {
	/* Load font from QResourceStream */
    font.loadFromStream(fontStream("://BitFont.ttf"));

	/* Set font properties */
    text.setFont(font);
    text.setCharacterSize(50);
	text.setFillColor({20, 240, 20});
}

void DateWidget::OnUpdate() {
	/* Catch up with widget size */
	sf::RenderWindow::setSize(qsf::QVector2u(static_cast<QWidget*>(QWidget::parent())->size()));

	for(sf::Event ev; this->pollEvent(ev);) {
		if(ev.type == sf::Event::MouseButtonPressed) {
			std::cout << "Click: [" << ev.mouseButton.x << ", " << ev.mouseButton.y << "]" << std::endl;
		}
	}

	/* Get & update view */
	sf::View view = this->getDefaultView();
	view.setSize({
		this->getSize().x,
		this->getSize().y
	});

	/* Apply view */
	this->setView(view);

	/* Clear */
    clear({20, 20, 20});

	/* Set text string and position */
    text.setString(qsf::String(QDateTime::currentDateTime().toString()));
	text.setPosition({(widgetSize.x - text.getGlobalBounds().width) / 2, text.getPosition().y});

	/* Draw text */
    draw(text);
}

void DateWidget::OnDestroy() {
	/* Print msg */
	std::cout << "\"You killed me!\"\n   ~" << std::hex << static_cast<void*>(this) << std::endl;
}
