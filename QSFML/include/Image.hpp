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
		Image();
		Image(QImage& qImg);

		QImage asQImage();
		void loadFromQImage(const QImage& qImg);
	};
}

#endif // FEW_H
