#include "QSFMLCanvas.hpp"
#include <SFML/System.hpp>
#include "keyconverter.hpp"

//Mouse events
void QSFMLWidget::mousePressEvent(QMouseEvent *e)
{
    sf::Event ev;
    ev.type = sf::Event::MouseButtonPressed;

    ev.mouseButton.button = (e->buttons() == Qt::RightButton ? sf::Mouse::Right : sf::Mouse::Left);
    ev.mouseButton.x = e->localPos().x();
    ev.mouseButton.y = e->localPos().y();

    pushEvent(ev);
}
void QSFMLWidget::mouseReleaseEvent(QMouseEvent *e)
{
    sf::Event ev;
    ev.type = sf::Event::MouseButtonReleased;

    ev.mouseButton.button = (e->buttons() == Qt::RightButton ? sf::Mouse::Right : sf::Mouse::Left);
    ev.mouseButton.x = e->localPos().x();
    ev.mouseButton.y = e->localPos().y();

    pushEvent(ev);
}

//Keyboard events
void QSFMLWidget::keyPressEvent(QKeyEvent *event)
{
    sf::Event ev;
    ev.type = sf::Event::KeyPressed;
    ev.key.code = QtKeyToSFML(event->key());

    pushEvent(ev);
}
void QSFMLWidget::keyReleaseEvent(QKeyEvent *event)
{
    sf::Event ev;
    ev.type = sf::Event::KeyReleased;
    ev.key.code = QtKeyToSFML(event->key());

    pushEvent(ev);
}
