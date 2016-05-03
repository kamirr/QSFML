#include "qresourcestream.hpp"

#include <iostream>
namespace qsf
{
    QResourceStream::QResourceStream()
    {
        this->pos = 0;
        this->size = 0;
    }
    QResourceStream::~QResourceStream()
    {
        if(size != 0)
            free(dat);
    }

    bool QResourceStream::open(const char* path)
    {
        if(this->size != 0)
        {
            free(dat);
            this->size = 0;
            this->pos = 0;
        }

        QFile file(path);
        if(!file.open(QIODevice::ReadOnly))
            return false;

        this->size = file.size();
        dat = malloc(file.size());

        if(dat == NULL)
            return false;

        if(file.read((char*) dat, file.size() + 1) == -1)
            return false;

        file.close();
        return true;
    }

    sf::Int64 QResourceStream::read(void *data, sf::Int64 size)
    {
        sf::Int64 i;
        for(i = 0; i < size && i + pos < this->size; i++, pos++)
            ((char*)data)[i] = ((char*)dat)[pos];

        return i;
    }
    sf::Int64 QResourceStream::seek(sf::Int64 position)
    {
        pos = position;
        return tell();
    }
    sf::Int64 QResourceStream::tell()
    {
        return pos;
    }
    sf::Int64 QResourceStream::getSize()
    {
        return this->size;
    }

    QResourceStream & QResourceStream::operator()(const char* path)
    {
        open(path);
        return *this;
    }
}
