<img src="https://raw.githubusercontent.com/KoczurekK/QSFML/master/logo/qsfml-original.png" width="300">

# QSFML
Library that integrates SFML 2.3.x (2.4.0 couses yet unsolved problem) and Qt 5.x.x, includes event handling, universal types, useful functions (eg. key code converter) etc.

# Installation
## Source code
$ git clone https://github.com/KoczurekK/QSFML.git

$ cd QSFML/QSFML/src

$ qmake

$ make

Then copy .dll/.so and include directory wherever you want to. 

## Deb packages
Download .deb packages from last release and install them.

# Compilation
All header files are in QSFML subdirectory, include useful ones and remember to link with -lQSFML.

# Origins
Basic code, on top of which im writing QSFML, was created by "jueves", you can find original post here: http://becomingindiedev.blogspot.com/2013/10/qt-5-and-sfml-20-integration.html
