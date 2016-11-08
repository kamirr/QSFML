/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com			  *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

//! @file
//! QVector2 implementation file

#ifndef QVECTOR2_HPP
#define QVECTOR2_HPP

#include <SFML/System/Vector2.hpp>
#include <QPoint>
#include <QSize>

namespace qsf {
	//! \class QVector2
	//! \brief Compatibility layer sf::Vector2<N> ↔ QPoint; QSize
	//!
	//! One Vector2 to rule them all.\n
	//! Inherits sf::Vector2<N>, so it can be used everywhere, where original vector can.\n
	//! Supports casting (non-explicit) to both QPoint and QSize.\n
	//! Sample usage:
	//! \code{.cpp}
	//! //Initialize using QSize
	//! qsf::Qvector2f factor(QWidget::size());
	//!
	//! //Use in SFML entity
	//! someRect.setSize(factor);
	//! \endcode
	template <typename N>
	class QVector2
		: public sf::Vector2<N> {
	public:
		//! \brief Default constructor
		//!
		//! Just calls default constructor of sf::Vector2<N>().
		QVector2()
			: sf::Vector2<N>()
		{ }

		//! \brief Two-parameter constructor
		//!
		//! \param [in] x – Point position on X axis
		//! \param [in] y – Point position on Y axis
		//!
		//! Calls sf::Vector2<N>(x, y).
		QVector2(N x, N y)
			: sf::Vector2<N>(x, y)
		{ }

		//! \brief Constructor copying sf::Vector2<N>
		//!
		//! \param [in] vec – Vector to copy
		//!
		//! Calls sf::Vector2<N>(vec.x, vec.y).
		QVector2(sf::Vector2<N> vec)
			: sf::Vector2<N>(vec.x, vec.y)
		{ }

		//! \brief Constructor copying QPoint
		//!
		//! \param [in] Qp – QPoint instance
		//!
		//! Calls sf::Vector2<N>(Qp.x(), Qp.y()).
		QVector2(QPoint Qp)
			: sf::Vector2<N>(Qp.x(), Qp.y())
		{ }

		//! \brief Constructor copying QSize
		//!
		//! \param [in] Qp – QSize instance
		//!
		//! Calls sf::Vector2<N>(Qp.x(), Qp.y()).
		QVector2(QSize Qp)
			: sf::Vector2<N>(Qp.width(), Qp.height())
		{ }

		//! \brief QPoint cast operator
		//!
		//! Casts qsf::Vector2 to a QPoint.\n
		//! Sample usage:
		//! \code{.cpp}
		//! qsf::QVector2f pos = {
		//!		rand() % 20 - 10,
		//!		rand() % 20 - 10
		//! };
		//! QWidget::move(pos);
		//! \endcode
		operator QPoint const() { return QPoint(N(this->x), N(this->y)); }

		//! \brief QSize cast operator
		//!
		//! \code{.cpp}
		//! qsf::QVector2f size = {
		//!		rand() % 200 + 100,
		//!		rand() % 200 + 100
		//! };
		//! QWidget::resize(size);
		//! \endcode
		operator QSize const()  { return QSize(N(this->x),  N(this->y)); }
	};

	//! \brief Alias to QVector with template int
	//!
	//! \code QVector2 <int> \endcode
	typedef QVector2<int>			QVector2i;

	//! \brief Alias to QVector with template unsigned int
	//!
	//! \code QVector2 <unsigned int> \endcode
	typedef QVector2<unsigned int>	QVector2u;

	//! \brief Alias to QVector with template float
	//!
	//! \code QVector2 <float> \endcode
	typedef QVector2<float>			QVector2f;

}
#endif // QVECTOR2_HPP

