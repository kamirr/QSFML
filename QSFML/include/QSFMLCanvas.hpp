/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com			  *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

/*! \mainpage QSFML
 *
 * \section About
 *
 * Library that integrates SFML 2.3.x; 2.4.1+ (2.4.0 causes a X11-related problem) and Qt 5, includes event handling, universal types, useful functions (eg. key code converter) etc.
 *
 * \section Installation
 * \subsection Compile
 *   - git clone https://github.com/KoczurekK/QSFML.git
 *   - cd QSFML/QSFML/src
 *   - qmake
 *   - make
 * \subsection Deb packages
 * Download .deb packages from leatest github release and install using dpkg/apt etc.
 *
 * \section Usage
 * All header files are in QSFML subdirectory, include useful ones and remember to link with -lQSFML.
 *
 * \section Origins
 * Basic code, on top of which im writing QSFML, was created by "jueves", you can find original post <a href=" http://becomingindiedev.blogspot.com/2013/10/qt-5-and-sfml-20-integration.html">here</a>
 */


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

//! \brief Namespace containing all qsf classes and methods.
namespace qsf {
	class QSFMLWidget
	: public QWidget,
	public sf::RenderWindow {
	public:
		explicit QSFMLWidget(QWidget *parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime = 7); //Defauld frame time should give about 144 FPS
		virtual ~QSFMLWidget();

		virtual void showEvent(QShowEvent*);
		virtual QPaintEngine* paintEngine() const;
		virtual void paintEvent(QPaintEvent*);

		virtual void OnInit();
		virtual void OnUpdate();
		virtual void OnDestroy();

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
