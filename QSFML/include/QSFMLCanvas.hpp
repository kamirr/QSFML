/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com              *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#ifndef QSFMLCANVAS_H
#define QSFMLCANVAS_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <qdebug.h>
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
		virtual void OnUpdate();

		bool pollEvent(sf::Event & ev);

		/* =============== *
		 * EVENTS HANDLING *
		 * =============== */
		//Mouse buttons
		void mousePressEvent(QMouseEvent *e);
		void mouseReleaseEvent(QMouseEvent *e);

		//Mouse wheel
		void wheelEvent(QWheelEvent *e);

		//Keyboard
		void keyPressEvent(QKeyEvent *e);
		void keyReleaseEvent(QKeyEvent *e);

		//Resize event
		void resizeEvent(QResizeEvent *event);

	private:
		bool _initialized;
		QTimer refreshTimer;
		sf::Time _frameTime;
		sf::Clock frameClock;

	protected:
		const bool & initialized = _initialized;
		const sf::Time & frameTime = _frameTime;

		void pushEvent(sf::Event & ev);
		std::vector<sf::Event> SfEvents;
	};
}
#endif // QSMLCANVAS_H
