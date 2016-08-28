/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com              *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#include "QSFMLCanvas.hpp"
#include <SFML/System.hpp>
#include "keyconverter.hpp"

namespace qsf
{
    //Mouse buttons events
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

    //Mouse Wheel events
    void QSFMLWidget::wheelEvent(QWheelEvent *e)
    {
        sf::Event ev;
        ev.type = sf::Event::MouseWheelMoved;

        ev.mouseWheel.delta = e->delta() / 8 / 15;
        ev.mouseWheel.x = sf::Mouse::getPosition(*this).x;
        ev.mouseWheel.y = sf::Mouse::getPosition(*this).y;

        pushEvent(ev);
        e->accept();
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
}
