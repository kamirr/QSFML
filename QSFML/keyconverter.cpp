#ifndef KEYCONVERTER_CPP
#define KEYCONVERTER_CPP

#include "keyconverter.hpp"

sf::Keyboard::Key QtKeyToSFML(int QtKey)
{
    switch (QtKey)
    {
        /* NUMBERS */
        case Qt::Key_0: return sf::Keyboard::Num0;
        case Qt::Key_1: return sf::Keyboard::Num1;
        case Qt::Key_2: return sf::Keyboard::Num2;
        case Qt::Key_3: return sf::Keyboard::Num3;
        case Qt::Key_4: return sf::Keyboard::Num4;
        case Qt::Key_5: return sf::Keyboard::Num5;
        case Qt::Key_6: return sf::Keyboard::Num6;
        case Qt::Key_7: return sf::Keyboard::Num7;
        case Qt::Key_8: return sf::Keyboard::Num8;
        case Qt::Key_9: return sf::Keyboard::Num9;

        /* ALPHABET */
        case Qt::Key_A: return sf::Keyboard::A;
        case Qt::Key_B: return sf::Keyboard::B;
        case Qt::Key_C: return sf::Keyboard::C;
        case Qt::Key_D: return sf::Keyboard::D;
        case Qt::Key_E: return sf::Keyboard::E;
        case Qt::Key_F: return sf::Keyboard::F;
        case Qt::Key_G: return sf::Keyboard::G;
        case Qt::Key_H: return sf::Keyboard::H;
        case Qt::Key_I: return sf::Keyboard::I;
        case Qt::Key_J: return sf::Keyboard::J;
        case Qt::Key_K: return sf::Keyboard::K;
        case Qt::Key_L: return sf::Keyboard::L;
        case Qt::Key_M: return sf::Keyboard::M;
        case Qt::Key_N: return sf::Keyboard::N;
        case Qt::Key_O: return sf::Keyboard::O;
        case Qt::Key_P: return sf::Keyboard::P;
        case Qt::Key_Q: return sf::Keyboard::Q;
        case Qt::Key_R: return sf::Keyboard::R;
        case Qt::Key_S: return sf::Keyboard::S;
        case Qt::Key_T: return sf::Keyboard::T;
        case Qt::Key_U: return sf::Keyboard::U;
        case Qt::Key_V: return sf::Keyboard::V;
        case Qt::Key_W: return sf::Keyboard::W;
        case Qt::Key_X: return sf::Keyboard::X;
        case Qt::Key_Y: return sf::Keyboard::Y;
        case Qt::Key_Z: return sf::Keyboard::Z;

        /* OTHERS */
        case Qt::Key_Space: return sf::Keyboard::Space;
        case Qt::Key_Return: return sf::Keyboard::Return;
        case Qt::Key_Backslash: return sf::Keyboard::BackSlash;
        case Qt::Key_Backspace: return sf::Keyboard::BackSpace;

    default:
        return sf::Keyboard::Return;
    }
}

#endif // KEYCONVERTER_CPP

