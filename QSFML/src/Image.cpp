#include "Image.hpp"

namespace qsf {
	Image::Image()
	: sf::Image()
	{ }

	Image::Image(QImage& qImg) {
		this->loadFromQImage(qImg);
	}

	QImage Image::asQImage() {
		return QImage(
			this->getPixelsPtr(),
			this->getSize().x,
			this->getSize().y,
			QImage::Format_RGBA8888
		);
	}

	void Image::loadFromQImage(const QImage& qImg) {
		QImage qImgRGBA = qImg.convertToFormat(QImage::Format_RGBA8888);

		this->create(
			qImgRGBA.size().width(),
			qImgRGBA.size().height(),
			qImgRGBA.bits()
		);
	}
}
