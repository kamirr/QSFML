/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com              *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */
//! @file
//! File containing qsf::Image class declaration

#ifndef QSF_IMAGE_HPP
#define QSF_IMAGE_HPP

#include <SFML/Graphics/Image.hpp>
#include <QImage>

namespace qsf {
	//! \brief sf::Image ↔ QImage compatibility layer
	//!
	//! \class qsf::Image
	//!
	//! Very simple class that inherits sf::Image. Its only additional purpose is being able to create QImage and to be loaded from such.
	class Image
	: public sf::Image {
	public:
		//! \brief Default constructor
		//!
		//! Calls sf::Image's default constructor.
		Image();

		//! \brief Constructor taking reference to QImage
		//!
		//! \param [in] qImg – const reference to QImage
		//!
		//! Calls loadFromQImage(img) to create qsf::Image.
		Image(const QImage& qImg);

		//! \brief Converts to QImage
		//!
		//! Creates QImage using sf::Image data, way faster than creating qsf::Image from QImage, as sf::Image always uses RGBA8888 format.
		QImage asQImage();

		//! \brief Load image from QImage
		//!
		//! \param [in] qImg – const reference to QImage
		//!
		//! Creates qsf::Image using QImage's data, slow as it has to copy QImage (to ensure, that it has proper format) and then copies it again into sf::Image backend.
		void loadFromQImage(const QImage& qImg);
	};
}

#endif // FEW_H
