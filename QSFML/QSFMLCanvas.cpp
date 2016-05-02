#include "QSFMLCanvas.hpp"

#ifdef Q_WS_X11
    #include <Qt/qx11info_x11.h>
    #include <X11/Xlib.h>
#endif

QSFMLCanvas::QSFMLCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime)
    : QWidget(Parent),
      initialized(false)
{
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);

    setFocusPolicy(Qt::StrongFocus);

    move(Position);
    resize(Size);

    refreshTimer.setInterval(FrameTime);
    frameClock.restart();
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
    OnUpdate(frameClock.restart());
    RenderWindow::display();
}

void QSFMLCanvas::OnInit()                      {} /* TO BE DERIVED */
void QSFMLCanvas::OnUpdate(sf::Time frameTime)  {} /* TO BE DERIVED */

bool QSFMLCanvas::pollEvent(sf::Event& ev)
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
