#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H

#include <SFML/Graphics.hpp>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>
#include <QTimer>

namespace qsf
{
    class QSFMLWidget
        : public QWidget,
          public sf::RenderWindow
    {
    public:
        explicit QSFMLWidget(QWidget *parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 7); //Defauld frame time should give about 144 FPS
        virtual ~QSFMLWidget();

        virtual void showEvent(QShowEvent*);
        virtual QPaintEngine* paintEngine() const;
        virtual void paintEvent(QPaintEvent*);

        virtual void OnInit();
        virtual void OnUpdate(sf::Time frameTime);

        bool pollEvent(sf::Event & ev);

        /* =============== *
         * EVENTS HANDLING *
         * =============== */
        //Mouse
        void mousePressEvent(QMouseEvent *e);
        void mouseReleaseEvent(QMouseEvent *e);

        //Keyboard
        void keyPressEvent(QKeyEvent *event);
        void keyReleaseEvent(QKeyEvent *event);

    private:
        bool _initialized;
        sf::Clock frameClock;
        QTimer refreshTimer;

    protected:
        const bool & initialized = _initialized;
        void pushEvent(sf::Event & ev);
        std::vector<sf::Event> SfEvents;
    };
}
#endif // QSMLCANVAS_H
