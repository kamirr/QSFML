/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com			  *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#include "QSFMLCanvas.hpp"

#ifdef Q_WS_X11
	#include <Qt/qx11info_x11.h>
	#include <X11/Xlib.h>
#endif

namespace qsf {
	QSFMLWidget::QSFMLWidget(QWidget* Parent, const QPoint& Position, const QSize& Size, unsigned int FrameTime)
		: QWidget(Parent),
		  _initialized(false) {
		setAttribute(Qt::WA_PaintOnScreen);
		setAttribute(Qt::WA_OpaquePaintEvent);
		setAttribute(Qt::WA_NoSystemBackground);

		setFocusPolicy(Qt::StrongFocus);

		move(Position);
		resize(Size);

		refreshTimer.setInterval(FrameTime);
		frameClock.restart();
	}
	QSFMLWidget::~QSFMLWidget() {
		OnDestroy();
	}


	void QSFMLWidget::showEvent(QShowEvent*) {
		if (!_initialized)
		{
			RenderWindow::create((sf::WindowHandle) winId());

			OnInit();

			connect(&refreshTimer, SIGNAL(timeout()), this, SLOT(repaint()));
			refreshTimer.start();
			_initialized = true;
		}
	}

	QPaintEngine* QSFMLWidget::paintEngine() const {
		return 0;
	}
	void QSFMLWidget::paintEvent(QPaintEvent*) {
		_frameTime = frameClock.restart();
		OnUpdate();
		RenderWindow::display();
	}

	void QSFMLWidget::OnInit()	{} /* TO BE DERIVED */
	void QSFMLWidget::OnUpdate()  {} /* TO BE DERIVED */
	void QSFMLWidget::OnDestroy() {} /* TO BE DERIVED */

	bool QSFMLWidget::pollEvent(sf::Event& ev) {
		if(SfEvents.size() == 0)
			return false;

		ev = SfEvents.back();
		SfEvents.pop_back();

		return true;
	}
	void QSFMLWidget::pushEvent(sf::Event & ev) {
		SfEvents.push_back(ev);
	}

	bool QSFMLWidget::isInitialized() {
		return this->_initialized;
	}

	sf::Time QSFMLWidget::getDeltaTime() {
		return this->_frameTime;
	}
}
