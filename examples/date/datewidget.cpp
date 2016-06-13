#include "datewidget.hpp"

DateWidget::DateWidget(QWidget *parent, const QPoint &Position, const QSize &Size)
    : qsf::QSFMLWidget(parent, Position, Size, 50),
      widgetSize(Size)
{ }

void DateWidget::OnInit()
{
    font.loadFromStream(fontStream("://BitFont.ttf"));

    text.setFont(font);
    text.setCharacterSize(50);
    text.setColor({20, 240, 20});
}

void DateWidget::OnUpdate()
{
    clear({20, 20, 20});

    text.setString(qsf::String(QDateTime::currentDateTime().toString()));
    text.setPosition({(widgetSize.x - text.getGlobalBounds().width) / 2, text.getPosition().y});

    draw(text);
}
