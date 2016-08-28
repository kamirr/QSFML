/* =========================================================== *
 * QSFML (c) Kamil Koczurek | koczurekk@gmail.com              *
 * GNU GPL v3 License http://www.gnu.org/licenses/gpl-3.0.html *
 * =========================================================== */

#ifndef QRESOURCESTREAM_H
#define QRESOURCESTREAM_H

#include <SFML/System/InputStream.hpp>
#include <QFile>

namespace qsf
{
    class QResourceStream
        : public sf::InputStream
    {
    public:
        QResourceStream();
        ~QResourceStream();

        bool open(const char* path);

        virtual sf::Int64 read(void* data, sf::Int64 size);
        virtual sf::Int64 seek(sf::Int64 position);
        virtual sf::Int64 tell();
        virtual sf::Int64 getSize();

        QResourceStream & operator()(const char* path);

    private:
        void * dat;
        sf::Int64 pos;
        sf::Int64 size;
    };
}
#endif // QRESOURCESTREAM_H
