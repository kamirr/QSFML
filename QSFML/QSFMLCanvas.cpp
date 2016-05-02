#include "QSFMLCanvas.hpp"
#ifdef Q_WS_X11
#include <Qt/qx11info_x11.h>
#include <X11/Xlib.h>
#endif
#include <iostream>
QSFMLCanvas::QSFMLCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime)
    : QWidget(Parent),
      initialized(false)
{

    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    move(Position);
    resize(Size);

    refreshTimer.setInterval(FrameTime);
}
QSFMLCanvas::~QSFMLCanvas() {}
void QSFMLCanvas::showEvent(QShowEvent*)
{
    if (!initialized)
    {
        RenderWindow::create((sf::WindowHandle) winId());

        OnInit();

        connect(&refreshTimer, SIGNAL(timeout()), this, SLOT(repaint()));
        refreshTimer.start();
        initialized = true;
    }
}

QPaintEngine* QSFMLCanvas::paintEngine() const
{
    return 0;
}
void QSFMLCanvas::paintEvent(QPaintEvent*)
{
    OnUpdate();
    RenderWindow::display();
}

void QSFMLCanvas::OnInit()   {} /* TO BE DERIVED */
void QSFMLCanvas::OnUpdate() {} /* TO BE DERIVED */

bool QSFMLCanvas::pollEvent(sf::Event & ev)
{
    if(SfEvents.size() == 0)
        return false;

    ev = *(SfEvents.end() - 1);
    SfEvents.erase(SfEvents.end() - 1);

    return true;
}
void QSFMLCanvas::pushEvent(sf::Event & ev)
{
    SfEvents.push_back(ev);
}

void QSFMLCanvas::mousePressEvent(QMouseEvent *e)
{
    sf::Event ev;
    ev.type = sf::Event::MouseButtonPressed;

    ev.mouseButton.button = (e->buttons() == Qt::RightButton ? sf::Mouse::Button::Right : sf::Mouse::Button::Left);
    ev.mouseButton.x = e->localPos().x();
    ev.mouseButton.y = e->localPos().y();

    pushEvent(ev);
}
void QSFMLCanvas::mouseReleaseEvent(QMouseEvent *e)
{
    sf::Event ev;
    ev.type = sf::Event::MouseButtonReleased;

    ev.mouseButton.button = (e->buttons() == Qt::RightButton ? sf::Mouse::Button::Right : sf::Mouse::Button::Left);
    ev.mouseButton.x = e->localPos().x();
    ev.mouseButton.y = e->localPos().y();

    pushEvent(ev);
}
