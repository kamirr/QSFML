/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com			  *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */
//! @file
//! File containg QResourceStream declaration

#ifndef QRESOURCESTREAM_H
#define QRESOURCESTREAM_H

#include <SFML/System/InputStream.hpp>
#include <ostream>
#include <QFile>

namespace qsf {
	//! \class QResourceStream
	//! \brief sf::InputStream reading QResource files
	//!
	//! This class inherits sf::InputStream, so it can by used by any SFML method that takes reference to such object. Therafore you can store your textures,
	//! sounds etc. in an execatulable/binary file using Qt resources and then read them thanks to this class.
	class QResourceStream
	: public sf::InputStream {
	public:
		//! \brief Default constructor
		//!
		//! Does nothing expect of setting private variables to proper values.
		QResourceStream();

		//! \brief Destructor
		//!
		//! Frees resources (memory).
		~QResourceStream();

		//! \brief Opens file
		//!
		//! \param [in]	path – Path to file
		//!
		//! \return True if file was opened and read properly, False otherwise.
		//!
		//! Opens given file, loads its contents to memory and then closes it.
		bool open(const char* path);

		//! \brief Reads parts of resource
		//!
		//! \param [in] size – Amount of thata to be read
		//! \param [out] data – Pointer to place, where data should be copied
		//!
		//! \return New position of cursor in file.
		virtual sf::Int64 read(void* data, sf::Int64 size);

		//! \brief Sets new cursor's position
		//!
		//! \param [in] position – New position
		//!
		//! \return New position of cursor in file.
		virtual sf::Int64 seek(sf::Int64 position);

		//! \brief Returns cursor's position
		//!
		//! \return New position of cursor in file.
		virtual sf::Int64 tell();

		//! \brief Returns file size
		//!
		//! \return File size.
		virtual sf::Int64 getSize();

		//! \brief Open a file using operator()
		//!
		//! \param [in] path – Path to file
		//!
		//! \return Reference to *this (the same object).
		//!
		//! Opens a file and then returns reference, discards informations about file being opened properly.
		//! Such a structure allows writing code like that:
		//! \code{.cpp}
		//! QResourceStream resource;
		//!
		//! /* Other code */
		//!
		//! someTexture.loadFromStream(resource("://BitTexture.png"));
		//! someMusic.loadFromStream(resource("://BitMusic.wav"));
		//! \endcode
		//! So you don't need to declare many instances of QResourceStream.
		QResourceStream & operator()(const char* path);

		//! \brief Prints whole file
		//!
		//! Allows printing file to std::ostream.\n
		//! Sample usage:
		//! \code{.cpp}
		//! QResourceStream resource;
		//! if(!resource.open("://BuiltInFile.txt")) {
		//!		std::cerr << "Could not read resource!" << std::endl;
		//! } else {
		//!		std::cout << "Content:" << std::endl << resource << std::endl;
		//! }
		//! \endcode
		friend std::ostream& operator <<(std::ostream& out, QResourceStream& resource);
	private:
		void * dat;
		sf::Int64 pos;
		sf::Int64 size;
	};
}
#endif // QRESOURCESTREAM_H
